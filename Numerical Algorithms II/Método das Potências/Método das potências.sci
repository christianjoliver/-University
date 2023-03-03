clear
clc
format(17)

//A={1 0 0; 1 1 -2;0 1 -1}; // NAO DÁ PRA CALCULAR, NUMERO COMPLEXO;
//yo={1; 1; 1};

//A={3 2 1; 1 4 1;1 2 3}; // DEU CERTO, SPEC = (2 6 2) E O RESULTADO DEU 5.9981718
//yo={1; 0; 0};

//A={3 3 -2; 0 -1 0; 8 6 -5}; // NAO DÁ PRA CALCULAR, NUMERO COMPLEXO;
//yo={1; 0; 0};

//A={1 -1 0; 2 3 2;1 1 2}; // DEU CERTO, SPEC = (2 3 1) E O RESULTADO DEU 3.005
//yo={1; 0; 0};

//A={3 -1 -3; 0 2 -3;0 0 -1}; // DEU CERTO, SPEC = (3 2 -1) E O RESULTADO DEU 3
//yo={1; 0; 0};

A={1 2 1; -1 3 1;0 2 2}; // DEU CERTO, SPEC = (3 2 1) E O RESULTADO DEU 3.00458813
yo={1; 0; 0};


//erro
function output = calcErroF(alpha2, alpha1);
    output = abs(alpha2-alpha1)/abs(alpha2);
endfunction

function main()
    i = 1;
    z1 = A*yo;  
    alpha1=max(abs(z1));
    y1 = (1/alpha1)*z1;
    printf("\n\tIteracao %d", i);
    disp(y1);
    disp(alpha1);  
    i=i+1;
    
    while(1)
        z2 = A*y1;
        alpha2 = max(abs(z2));
        y2 = (1/alpha2)*z2;
        if(calcErroF(alpha2, alpha1)<0.00001) break; end;
        y1 = y2;
        alpha1 = alpha2; 
        printf("\n\tIteracao %d", i);
        disp(y1);
        disp(alpha2);
        i = i+1;
    end
    printf("\n\tIteracao %d", i);
    disp(y1);
    disp(alpha2);
endfunction
main()
