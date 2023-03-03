clear
clc
format(15)

// sistema de eq.
function output = F(fxn);
    A(1) = fxn(1)^2 + ((2*fxn(2)^2) - fxn(2)) - 2*fxn(3);
    A(2) = fxn(1)^2 - (8*fxn(2)^2) + 10*fxn(3);
    A(3) = ((fxn(1)^2)/(7*fxn(2)*fxn(3)))-1;
    output = A;
endfunction

// jacobiana do sistema de eq.
function output = J(x1, x2, x3);
    output = [2*x1, 4*x2-1, -2; 2*x1, -16*x2, 10; 2*x1/(7*x2*x3), -(x1^2)/(7*(x2^2)*x3), -(x1^2)/(7*x2*(x3^2))];
endfunction

// erro entre duas matrizes
function output = calcErroMat(x1, x2);
    output = max(abs(x2 - x1));
endfunction

// erro da aplicacao do ponto na funcao
function output = calcErroF(x);
    output = max(abs(F(x)));
endfunction

function main()
    i = 2;    
    x0 = [0.5; 0.3; 0.07]; //6, 1, -4
    erro = 10^-4;
    
    // primeira iteracao;
    printf("\tIteracao 1");
    fx0 = F(x0);
    wx0 = J(x0(1), x0(2), x0(3));
    S = linsolve(wx0, fx0);
    x1 = x0 + S;
    erroM = calcErroMat(x1, x0);
    erroF = calcErroF(x1);
    disp("x1 = ");
    disp(x1);
//    disp("Erro | Xn - Xn-1 |: ")    
//    disp(erroM);
//    disp("Erro F(X)");
//    disp(erroF);
    
    // segunda iteracao em diante;
    while(erroF>erro & erroM>erro)
        x0 = x1;
        printf("\n\tIteracao %d", i);
        fx0 = F(x0);
        S = linsolve(wx0, fx0);
        x1 = x0 + S;
        erroM = calcErroMat(x1, x0);
        erroF = calcErroF(x1);
        printf("\t\n x%d = ", i);
        disp(x1);  
        i = i+1;
    end
    printf("\nErro | Xn - Xn-1 |: ");
    disp(erroM);
    printf("\nErro F(X%d)", i);
    disp(erroF);
   
endfunction  
main();
