// Christian Jonas Oliveira
clear;
clc;
format(17);

//variaveis de entrada

h =0.1;

limiteInferiorIntervalo = 0;

limiteSuperiorIntervalo = 0.8;

tamanho = round((limiteSuperiorIntervalo - limiteInferiorIntervalo)/h);

j = 0;

while(j<3)
    y(1) = 1;
    x(1) = limiteInferiorIntervalo;
    i = 2;
    tamanho = round((limiteSuperiorIntervalo - limiteInferiorIntervalo)/h)
    printf("\n Para H = %f", h);
    if(j==0) then cor = 'r'; end;
    if(j==1) then cor = 'g'; end;
    if(j==2) then cor = 'b'; end;
    
    while (i <= tamanho+1)
        exec("FuncaoEuler_Ex2.sci");
        y(i) = y(i-1)+h*FuncaoEuler_Ex2(x(i-1), y(i-1));
        x(i) = x(i-1)+h;
        i = i+1;
    end
    erro = ((h*2)/1.6)*((%e**0.64) - 1);
    printf("\n Erro para h-> %f  ERRO = %f", h, erro);
    plot(x, y, cor);
    h = h/10;
    j = j+1;
end


