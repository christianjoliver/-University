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
    output = [2*x1, 4*x2-1, -2; 2*x1, -16*x2, 10; 2*x1/(7*x2*x3), -(x1^2)/(7*(x2^2)*x3), -(x1^2)/(7*x2*(x3^2))]^-1;
endfunction
 
// erro
function output = verErro(x, e)
    i = 1;
    for n = 1:length(x)
        if(x(n)>e) i = 0; end;
    end
    output = i;
endfunction

function main()
    i = 2;    
    x0 = [0.5; 0.3; 0.07];
    erro = 10^-4;
    
    // primeira iteracao;
    printf("\tIteracao 1");
    fx0 = F(x0);
    wx0 = J(x0(1), x0(2), x0(3));
    x1 = x0 - (wx0 * fx0);
    
    // segunda iteracao em diante;
    while(1)
        disp(x1);
        x0 = x1;
        fx0 = F(x0);
        if(verErro(fx0, erro)==1) break; end;
        printf("\n\tIteracao %d", i);
        wx0 = J(x0(1), x0(2), x0(3));
        x1 = x0 - (wx0 * fx0);
        i = i+1;
    end
    disp(fx0);
endfunction  
main();
