


def main():
    x = [1.4, 2.1, 3, 4.4]
    y = [4.2, 2.3, 1.9, 1.1]

    print(desvio(x, y))
    print(calc(x, y))
    print(var_resid(x, y))


def var_resid(x, y):
    soma = 0

    for i in range(len(y)):
        soma += (y[i]-(4.8885-0.9224*x[i]))**2

    return soma/3

def calc(x, y):
    soma = 0

    for i in range(len(x)):
        soma += (y[i] - 4.88854 + (0.9226*x[i]))**2

    return soma

def desvio(x, y):
    tam = len(x)
    soma = 0

    for i in range(tam):

        soma+=(y[i] - (-0.7273*x[i] + 4.3273))**2

    return soma





main()