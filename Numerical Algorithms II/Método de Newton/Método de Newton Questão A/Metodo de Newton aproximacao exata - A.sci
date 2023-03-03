clear
clc
format(17)

// sistema de eq.
function output = F(fxn);
    A(1) = fxn(1)^3 + 2*fxn(2) + fxn(3) - 4;
    A(2) = 2*fxn(1)^2 + (fxn(2)^2) - 4 * fxn(3) - 1;
    A(3) = 3*fxn(1)^2 - 4*fxn(2) + fxn(3);
    output = A;
endfunction

// jacobiana do sistema de eq.
function output = J(x);
    output = [3*x(1)^2, 2, 1; 4*x(1), 2*x(2), -4; 6*x(1), -4, 1]^-1;
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
    x0 = [1; 1; 2];
    erro = 0.0001;
    
    // primeira iteracao;
    printf("\tIteracao 1");
    fx0 = F(x0);
    wx0 = J(x0);
    x1 = x0 - (wx0 * fx0);
    
    if(verErro(fx0, erro)==1) disp(x1);
    // segunda iteracao em diante;
    else
        disp(x1);
        while(1)
            x0 = x1;
            fx0 = F(x0);
            if(verErro(fx0, erro)==1) break; end;
            printf("\n\tIteracao %d", i);
            wx0 = J(x0);
            x1 = x0 - (wx0 * fx0);
            disp(x1);
            i = i+1;
        end
    end
    printf("\nErro");
    disp(fx0);
endfunction  
main();
