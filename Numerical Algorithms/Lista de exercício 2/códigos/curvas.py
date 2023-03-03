import matplotlib.pyplot as plt


def main():

    y = [1.4, 2.1, 3, 4.4]
    x = [4.2, 2.3, 1.9, 1.1]

    b = B(x, y)
    a = A(x, y, b)

    plota_grafico(x, y, 0, 0)

    op = input("\n  Deseja avaliar o gráfico em algum ponto específico? s/n: ")

    if op=='s':

        ponto = float(input("\n   Digite o ponto no qual deseja ser avaliado: "))

        plota_grafico(x, y, 1, ponto)

    print("\n   O valor do desvio eh:", round(desvio(x, y), 6))
    print("\n   O valor a qualidade eh:", round(qualidade(x, y), 4))



def desvio(x, y):

    b = B(x, y)
    a = A(x, y, b)
    soma = 0

    for i in range(len(x)):
        soma += (y[i] - reta(a, b, x[i]))**2

    return soma


def qualidade(x, y):

    n = len(x)
    b = B(x, y)
    a = A(x, y, b)
    aux = 0
    somatorio = 0

    for i in range(n):

        somatorio += (y[i] - a - (b*x[i]))**2


    aux = soma_exp(y) - ((1/n) * (soma(y)**2))

    return 1 - (somatorio/aux)


def plota_grafico(x, y, op, ponto):

    tam = len(x)
    lal = []
    lel = []
    j = x[0]
    a = A(x, y, B(x, y))
    b = B(x, y)

    while (j < 10):

        lal.append(j)

        lel.append(reta(a, b, j))

        j += 0.1

    if (op!=1):
        plt.plot(x, y, 'o', label = 'Pontos dados')
        plt.plot(lal, lel, color = 'green', label = 'Curva por Mínimos quadrados')
        plt.title("{} + {}x".format(round(a, 4), round(b, 4)))
        plt.legend()
        plt.grid(1)
        plt.xlabel('Eixo X')
        plt.ylabel('Eixo Y')
        plt.show()

    else:
        f = [ponto]
        g = [reta(a, b, ponto)]
        plt.plot(x, y, 'o', color = 'blue', label='Pontos dados')
        plt.plot(f, g, 'o', color = 'red', label='Ponto Escolhido')
        plt.plot(lal, lel, color='green', label='Curva por Quadrados mínimos')
        plt.title("{} + {}x".format(round(a, 4), round(b, 4)))
        plt.legend()
        plt.grid(1)
        plt.xlabel('Eixo X')
        plt.ylabel('Eixo Y')
        plt.show()


def soma(x):

    soma = 0

    for i in range(len(x)):

        soma += x[i]

    return soma


def soma_prod(x, y):

    soma = 0

    for i in range(len(x)):

        soma += x[i]*y[i]

    return soma


def soma_exp(x):

    soma = 0

    for i in range(len(x)):

        soma += x[i]**2

    return soma


def B(x, y):

    n = len(x)

    return ((soma(x) * soma(y)) - (n * soma_prod(x, y))) / (soma(x)**2 - (n * soma_exp(x)))


def A(x, y, b):

    n = len(x)

    return (soma(y) - (round(B(x, y), 4) * soma(x)))/n


def reta(a, b, p):

    return a + b * p


main()