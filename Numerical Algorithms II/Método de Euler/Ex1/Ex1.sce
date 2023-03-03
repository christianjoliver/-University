// Christian Jonas Oliveira
clear;
clc;
format(17);

//variaveis de entrada

h =0.2;

limiteInferiorIntervalo = 1;

limiteSuperiorIntervalo = 2;


x(1)=limiteInferiorIntervalo;


j = 0;

while(j<3)
    i = 2;
    y(1) = 1;
    x(1) = limiteInferiorIntervalo;
    tamanho = round((limiteSuperiorIntervalo - limiteInferiorIntervalo)/h);
    
    if(j==0) then cor = 'r'; end;
    if(j==1) then cor = 'g'; end;
    if(j==2) then cor = 'b'; end;
    printf("\n Para H = %f", h);
    while (i <= tamanho+1)
        exec("FuncaoEuler_Ex1.sci");
        y(i) = y(i-1)+h*FuncaoEuler_Ex1(x(i-1), y(i-1));
        x(i) = x(i-1)+h;
        printf('\n Passo: %d - XY(%.4f ; %.4f)', i-1, x(i), y(i));
        i = i+1;
    end
    plot(x, y, cor);
    h = h/10;
    j = j+1;

end


