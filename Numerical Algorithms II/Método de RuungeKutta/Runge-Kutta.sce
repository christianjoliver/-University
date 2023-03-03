 //            Atividade de Fixacao 2 - Algoritmos Numericos II             //
//                  Criado por: Christian Jonas Oliveira                   //
//  Resolucao de EDO's pelos Metodos de Diferencas Finitas e Runge Kutta   //
clear
clc
format(17);
//          OBSERVACAO: DEVE-SE ALTERAR NO CODIGO O BLOCO                  //
//       REFERENTE AO CALCULO PELO METODO DAS DIFERENCAS FINITAS           //

// Bloco de alteracao pelo Programador/Usuario /////////
x0 = 0;
xn = 0.5;
y0 = 2;
xk = x0;
yk = y0;

h(1) = 0.1;
//h(2) = 0.2;
//h(3) = 0.1;
//h(4) = 0.05;

function output = funcao(x, y)
    output = -y + x + 2;
endfunction

///////////////////////////////////////////////////////

function output = RK(h)
    c = 2;
    count = round(xn/h)+2;
    A(1) = y0;
    while(xk < xn)    
        K1 = h * funcao(xk, yk); //A(c)(1) = K1;       
        K2 = h * funcao(xk + (h/2), yk + (K1/2)); //A(c)(2) = K2;       
        K3 = h * funcao(xk + (h/2), yk + (K2/2)); //A(c)(3) = K3;
        K4 = h * funcao(xk + h, yk + K3); //A(c)(4) = K4;
        yk = yk + (1/6) * (K1 + 2*K2 + 2*K3 + K4);
        
        A(c) = yk;
        
        xk = xk+h;
        c = c+1;
        
        if(c==count) c = 1; end   
    end
    xk = x0;    
    yk = y0;
    output = A;
endfunction

function imprimeMatriz(matriz, h); 
    ordem = round(xn/h)+1;
    for i=1:ordem
        printf("y%d = %.5f\n", i-1, matriz(i));
    end
endfunction

function output = montaX(h)
    X(1)=x0;
    count = x0+h;
    i = 2;
    for count=count:h:xn;
       X(i) = count;        
       count = count + h;
       i = i+1;  
    end
    
    output = X;
endfunction

function output = solExata(X, ordem)
    A(1) = y0;
    i = 2;
    while i <= ordem+1;
        A(i) = X(i) + 1 + (1/(%e^x(i)));
        i = i+1;
    end
    output = A;
endfunction

function output = funcaoA(h, lim, o)
    for i=1:o
        x(i)=((h*i)+lim);
        
        // Digite aqui o primeiro termo (que acompanha yi-1)
        primeiraParcela = -1;  
        
        // Digite aqui o segundo termo (que acompanha yi)                            
        parcelaDoMeio = 1+h;
        
        // Digite aqui o terceiro termo (que acompanha yi+1)                          
        ultimaParcela = 0;                                     
        for j=1:o    
            if (i-1>0)
                A(i)(i-1)= primeiraParcela;
            end
            
            A(i)(i)= parcelaDoMeio;
            
            if (i+1<=o)
                A(i)(i+1)= ultimaParcela;
            end
        end
    end   
    output = A;
endfunction

function output = funcaoB(h, vi, o) 
    for i=1:o
        x(i) = (h*i) + x0;
        // Digite aqui o primeiro termo (que acompanha yi-1)
        primeiraParcela = -1;  
        // Digite aqui a funcao que vem apos a igualdade
        funcB = h*(x(i)+2);
        if(i==1) then    
            B(i)(1)= ((-1)* vi * primeiraParcela + funcB);         
        else 
            B(i)(1) = funcB;                     
        end
   end
   output = B;
endfunction

function output = reorganiza(A)
    i = 1;
    B(1) = y0;
    for i=1:length(A) 
        B(i+1) = A(i);
    end
    output = B;
endfunction

function output = Erro (sExata, difFinitas)
    tam = length(sExata);
    for i=1:tam
        e(i) = abs(difFinitas(i) - sExata(i));
    end
    output = e;
endfunction
    
function main()
    i = 1;
    //for i=1:4
        printf("\n\n \t SOLUCAO \n")   
        ordem = round((xn-x0)/h(i));
        x = montaX(h(i));
        tit = "Para H = " + string(h(i));
        printf(tit);
        
        // Runge Kutta
        ya = RK(h(i));
        printf("\n Solucao Por Runge Kutta\n");  
        imprimeMatriz(ya, h(i));
        subplot(2, 2, i);
        plot(x, ya, 'r');
        
        // Solucao exata
        yb = solExata(x, ordem);
        printf("\n Solucao Exata\n");
        imprimeMatriz(yb, h(i));
        subplot(2, 2, i);
        plot(x, yb, 'b');
        
        // Diferencas Finitas  
        printf("\n Solucao Por Diferencas Finitas\n");
        A = funcaoA(h(i), x0, ordem);
        B = funcaoB(h(i), y0, ordem);
        S = linsolve(A, -B);
        S = reorganiza(S);
        imprimeMatriz(S, h(i));
        subplot(2, 2, i);
        plot(x, S, 'g');
        printf("\n");
        disp(A);
        printf("\n");
        disp(B);
        printf("\n");
        legend(['RK'; 'SE'; 'DF']);
        title(tit);
        
        printf("\n\n \t ERRO \n")
        printf("\n Por Diferencas Finitas\n")
        E1 = Erro(yb, S);
        imprimeMatriz(E1, h(i));
        printf("\n Por Runge Kutta\n")       
        E2 = Erro(yb, ya);
        imprimeMatriz(E2, h(i));
    //end
    
endfunction
main();
