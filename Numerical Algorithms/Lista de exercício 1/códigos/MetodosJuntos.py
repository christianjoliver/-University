import os
import matplotlib.pyplot as plt


class Poli(object):

    def __init__(self, grau, coeficiente):
        self.grau = grau
        self.coeficiente = coeficiente


def main():
    x = [0.5, 1.2, 2.1, 3.5, 5.4]
    y = [5.1,3.2, 2.8, 1, 0.4]

    grau = int(input("\n	Digite o grau do polinômio desejado: "))

    x_escolhido = []
    y_escolhido = []

    if (grau < len(x)):

        print("\n	Pontos informados:\n")

        for i in range(len(x)):
            print("		x[{}] = {}".format(i, x[i]))

        print("\n	Agora, digite o indice dos pontos que deverão ser operados: ")

        for i in range(grau + 1):
            e = int(input("\n	{}º Ponto : ".format(i + 1)))
            x_escolhido.append(x[e])
            y_escolhido.append(y[e])

        os.system("cls")
        print("\n	Digite o numero que corresponde ao metodo desejado: ")
        print("\n	1 - Metodo de Lagrange")
        print("\n	2 - Metodo de Newton")
        m = int(input("\n	"))
        print()

        if (m == 1):

            print("\nO polinomio resultante pelo metodo de lagrange eh: \n")

            lal = lagrange2(x_escolhido, y_escolhido)
            imprimePoly(lal, 1)
            print("\n\n")

            op = input("\n	Deseja avaliar a o polinomio em algum ponto especifico? (s/n):  ")

            if op == 's':
                p = float(input("\n 	Digite o ponto: "))
                print("\n	O polinomio aplicado ao ponto {} resulta em: {}".format(p,lagrange(x_escolhido, y_escolhido, p)))

            plota_grafico(x_escolhido, y_escolhido, lal, 1)

        if (m == 2):

            print("\nO polinomio resultante pelo metodo de Newton eh: \n")
            lel = newton2(x_escolhido, y_escolhido)
            imprimePoly(lel, 2)
            print("\n\n")

            op = input("\n	Deseja avaliar a o polinomio em algum ponto especifico? s/n  ")

            if op == 's':
                p = float(input("\n 	Digite o ponto: "))
                print("\n	O polinomio aplicado ao ponto {} resulta em: {}".format(p, newton(x_escolhido, y_escolhido, p)))

                if grau != len(x)-1:
                    print()
                    print("\n	O erro resultante e de : {}".format(erro_newton(x, y, p, grau, x_escolhido)))
                    print()

            plota_grafico(x_escolhido, y_escolhido, lel, 2)

    else:

        print("\n	Quantidade de pontos insuficientes. ")

    print("\n	Fim")


def plota_grafico(x, y, lel, metodo):
    tam = len(x)
    lal = []
    lel = []

    j = x[0]

    while (j < x[tam - 1]):
        lal.append(j)
        lel.append(lagrange(x, y, j))
        j += 0.01

    plt.plot(x, y, color='green', label='Curva dos pontos dados')
    plt.plot(lal, lel, color="orange", label='Funcao interpoladora')

    plt.scatter(x, y, color='red')
    plt.title("Interpolação Aplicada")
    plt.legend()
    plt.grid(1)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.show()


def erro_newton(x, y, p, grau, x_escolhido):
    h = dd(x, y)
    maior = 0
    produto = 1

    for i in range(len(x)):

        for j in range(1, grau + 2):

            if (abs(h[i][j]) > maior):
                maior = abs(h[i][j])

    for i in range(len(x_escolhido)):
        produto *= (p - x_escolhido[i])


    result = abs(produto) * abs(maior)

    return result


def newton(x, y, p):
    tam = len(x)

    soma = y[0]

    d_div = dd(x, y)

    for i in range(1, tam):

        mult = 1

        for j in range(i):
            mult = mult * (p - x[j])

        soma = soma + d_div[0][i] * mult

    return soma


def newton2(x, y):
    tam = len(x)

    soma = [Poli(0, y[0])]

    pol = [Poli(1, 1)]

    d_div = dd(x, y)

    for i in range(1, tam):

        mult = [Poli(0, 1)]

        for j in range(i):
            aux = s_poli(copiaLista(pol), [Poli(0, (-1) * x[j])])

            mult = m_poli(mult, aux)

        soma = s_poli(soma, m_poli([Poli(0, d_div[0][i])], mult))

    return soma


def dd(x, y):
    tam = len(x)

    #	guardando minha coluna 0

    x1 = x[:]

    mat = [[0] * tam for i in range(tam)]

    for i in range(tam):
        mat[i][0] = y[i]

    for i in range(1, tam):

        #	vai de 1 até tam-i pois quero preencher a matriz de modo a ficar num formato triangular

        for j in range(tam - i):
            mat[j][i] = (mat[j + 1][i - 1] - mat[j][i - 1]) / (x1[i + j] - x1[j])

    return mat


def lagrange(x, y, p):
    soma = 0
    tam = len(x)

    for i in range(tam):

        L = 1

        for j in range(tam):

            if i != j:
                L = L * (p - x[j]) / (x[i] - x[j])

        soma += y[i] * L

    return soma


def lagrange2(x, y):
    tam = len(x)

    soma = [Poli(-1, 0)]

    pol = [Poli(1, 1)]

    for i in range(tam):

        L = [Poli(0, 1)]

        for j in range(tam):

            if i != j:
                numerador = s_poli(copiaLista(pol), [Poli(0, (-1) * x[j])])

                denominador = x[i] - x[j]

                s = d_poli(numerador, denominador)

                L = m_poli(L, s)

        soma = s_poli(soma, m_poli([Poli(0, y[i])], L))

    return soma


def copiaLista(x):
    copia = []
    n = len(x)
    for i in range(0, n):
        coef = x[i].coeficiente
        grau = x[i].grau
        aux = Poli(grau, coef)
        copia += [aux]
    return copia


def imprimePoly(x, metodo):
    n = len(x)

    if metodo == 1:

        for i in range(n):

            if (x[i].coeficiente != 0):

                if (x[i].grau == 0):

                    if (x[i].coeficiente < 0):
                        print("- {}".format(abs(x[i].coeficiente)), end="")

                    else:
                        print("+ {}".format(x[i].coeficiente), end="")

                else:

                    if (x[i].coeficiente < 0):
                        print("- {}x^{} ".format(abs(x[i].coeficiente), x[i].grau), end="")

                    else:
                        print("+ {}x^{} ".format(x[i].coeficiente, x[i].grau), end="")

    if metodo == 2:

        for i in range(n - 1, -1, -1):

            if (x[i].coeficiente != 0):

                if (x[i].grau == 0):

                    if (x[i].coeficiente < 0):
                        print(" - {}".format(abs(x[i].coeficiente)), end="")

                    else:
                        print("+ {}".format(x[i].coeficiente), end="")

                else:

                    if (x[i].coeficiente < 0):
                        print(" - {}x^{} ".format(abs(x[i].coeficiente), x[i].grau), end="")

                    else:
                        print("+ {}x^{} ".format(x[i].coeficiente, x[i].grau), end="")


def d_poli(x, n):
    r = x[:]

    for i in range(len(x)):
        r[i].coeficiente /= n

    return r


def m_poli(x, y):
    r = []

    c = 0

    for i in range(len(x)):

        aux = []

        for j in range(len(y)):
            prod = x[i].coeficiente * y[j].coeficiente

            grau = x[i].grau + y[j].grau

            aux.append(Poli(grau, prod))

        r = s_poli(r, aux)

    return r

def s_poli(x, y):
    if len(x) == 0:
        return y

    if len(y) == 0:
        return x

    r = x[:]

    tam1 = len(y)

    for i in range(tam1):

        e = busca(r, y[i].grau)

        if e != -1:
            r[e].coeficiente += y[i].coeficiente

        else:
            r.append(y[i])

    return r

def busca(x, e):
    for i in range(len(x)):
        if (x[i].grau == e):
            return i
    return -1

main()