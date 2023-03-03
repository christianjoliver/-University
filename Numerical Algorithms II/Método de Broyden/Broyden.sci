clear
clc
format(15)

// sistema de eq.
disp("Questao B");
function output = F(fxn);
    A(1) = fxn(1)^2 + fxn(2)^2 + fxn(3)^2 - 1;
    A(2) = 2*fxn(1)^2 + (fxn(2)^2) - 4 * fxn(3);
    A(3) = 3*fxn(1)^2 - 4*fxn(2) + fxn(3);
    output = A;
endfunction

// jacobiana do sistema de eq.
function output = J(x);
    output = [2*x(1), 2*x(2), 2*x(1); 4*x(1), 2*x(2), -4; 6*x(1), -4, 1];
endfunction

// erro
function output = calcErroF(x);
    output = max(abs(s));
endfunction


function main()
    erro = 0.0001;
    i = 1;
    //passo 1
    x0 = [0.5; 0.5; 0.5];
    B = J(x0);
    Fx = F(x0);
    s = linsolve(B, Fx);
    
    if(calcErroF(s)<erro) disp(x0); 
    else
        while(1)
            x0 = x0 + s;
            Fx = F(x0);
            //disp(Fx);
            B = B + (1/(s'*s))*F(x0)*s';
            disp(F(x0)*s');
            s = linsolve(B, Fx);
            printf("\n\tIteracao %d", i);
            disp(x0);
            if(calcErroF(s)<erro) break end;
            i = i+1;
            
        end
    end
    disp("Erro");
    disp(calcErroF(s));
endfunction
main()
