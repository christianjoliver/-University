clear
clc
xi = 0;
xf = 1;

function output = calcX(h)
    i = 1;    
    aux = xi+h;
    while aux<xf
        X(i) = aux;
        aux = aux+h;
        i = i+1;
    end
    output = X;
endfunction

function output = f(X, ordem)
    for i=1:ordem
        A(i) =  4*X(i)*(2-X(i))//(X(i)^2) + 3*X(i);//X(i) * (1-X(i));//(X(i)^2) + 2*X(i);
    end
    output = A;
endfunction

function output = calcDelta(a, ordem)
    
    for i=1:ordem
        for j=1:ordem
            if (i==j) then
                A(i)(j) = 1 + (2*a)
            elseif(j==(i+1) | j==(i-1)) then 
                A(i)(j) = -a       
            else
                A(i)(j) = 0 
            end
        end
    end
    output = A;
endfunction


function main()
    printf("\nDigite o valor de H: ")
    [h] = scanf("%f");
    t = h;
    alpha = t/(h^2);
    
    ordem = ((xf - xi)/h)-1; 
    A = calcDelta(alpha, ordem);
    X = calcX(h);
    B = f(X, ordem);
    
    disp(A);
    printf("\n");
    disp(B);
    printf("\n");    
    disp(X);
    disp(linsolve(A, -B));
     
endfunction
main();
