clear;
clc;
format(17);

//variaveis de entrada
printf("Digite o valor de h:");
[h]=scanf("%f");

printf("Digite o valor do limite inferior:");
[limiteInferiorIntervalo]=scanf("%f");

printf("Digite o valor do limite superior:");
[limiteSuperiorIntervalo]=scanf("%f");

printf("Digite o valor do Y inicial (PVI):");
[y(1)]=scanf("%f");

x(1)=limiteInferiorIntervalo;

tamanho = 1.0f *(limiteSuperiorIntervalo - limiteInferiorIntervalo)/h;

i = 2;

while (i <= tamanho+1)
    exec("funcaoEuler.sci");
    y(i) = y(i-1)+h*funcaoEuler(x(i-1), y(i-1));
    x(i) = x(i-1)+h;
    printf('\n Passo: %d - XY(%.4f ; %.4f)', i-1, x(i), y(i));
    i = i+1;
end

plot(x, y, 'b');
