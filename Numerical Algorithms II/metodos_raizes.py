from sympy import *
from IPython.display import display, Math, Latex


class Polynomial:

    def __init__(self, *coeficiente):
        self.coeficiente = list(coeficiente)

    def __call__(self, x):

        #   metodo da classe Polynomial para retornar o resultado do polinomio aplicado a um x
        
        result = 0

        for i, coef in enumerate(self.coeficiente[::-1]):
            result += coef * (x ** i)

        return result

    def add(self, x):
        self.coeficiente.append(x)

    def printa(self):

        #   metodo para printar o polinomio, retorna uma tupla para ser printada com o módulo LaTeX

        grau = len(self.coeficiente) - 1

        x = Symbol('x')

        result = self.coeficiente[0] * x ** grau

        for i in range(1, len(self.coeficiente) - 1):
            result += self.coeficiente[i] * x ** (grau - i)

        result += self.coeficiente[-1]

        return result

    def derivative(self):
        
        #   metodo que deriva e retorna um polinomio

        coef_derivado = []

        expoente = len(self.coeficiente) - 1

        for i in range(len(self.coeficiente) - 1):
            coef_derivado.append(self.coeficiente[i] * expoente)

            expoente -= 1

        return Polynomial(*coef_derivado)


def main():
    p = Polynomial(0)
    init_printing(pretty_print=true)

    x = Symbol('x')

    r = int(input("Digite o grau: "))

    for i in range(r, -1, -1):
        x = int(input("Digite o coeficiente do monmio de grau {}: ".format(i)))
        p.add(x)

    while(True):
        print("-"*30)
        print("|\t\t1 - Bissecao         |")
        print("|\t\t2 - Newton           |")
        print("|\t\t3 - Secante          |")
        print("-" * 30)
        metodo = int(input("\tDigite o metodo desejado ou 0 para sair: "))

        if metodo == 1:
            display(p.printa())
            a = int(input("Digite a: "))
            b = int(input("Digite b: "))
            erro = float(input("Erro: "))
            print("\nraiz: ", round(bissecao(a, b, p, erro, 0), 8))

        elif metodo == 2:
            display(p.printa())
            x0 = float(input("Digite x: "))
            erro = float(input("Digite o erro: "))
            print("\nraiz: ", round(newton(x0, p, p.derivative(), erro, 0), 8))

        elif metodo == 3:
            display(p.printa())
            x0 = float(input("valor de x0: "))
            x1 = float(input("valor de x1: "))
            erro = float(input("Digite o erro: "))
            print("\nraiz: ", secante(x1, x0, p, erro, 0))

        else:
            break


def bissecao(a, b, poli, erro, i):
    p = (a + b) / 2

    #   se já tivermos com uma precisão ok, retorne p
    if abs(b - a) < erro:
        print("i-->{}\ta - {:.12f}\tb - {:.12f}\tp - {:.12f}\tf(a) - {:.12f}\tf(b) - {:.12f}\tf(p) - {:.12f}".format(i, a, b, p, poli(a), poli(b), poli(p)))
        return p

    #   se encontrarmos uma raiz, retorne-a
    if poli(p) == 0:
        print("i-->{}\ta - {:.12f}\tb - {:.12f}\tp - {:.12f}\tf(a) - {:.12f}\tf(b) - {:.12f}\tf(p) - {:.12f}".format(i, a, b, p, poli(a), poli(b), poli(p)))
        return p

    #   se o produto der menor que 0, saberemos que f(a) e f(p) tem sinais opostos entre si
    if poli(a) * poli(p) < 0:
        print("i-->{}\ta - {:.12f}\tb - {:.12f}\tp - {:.12f}\tf(a) - {:.12f}\tf(b) - {:.12f}\tf(p) - {:.12f}".format(i, a, b, p, poli(a), poli(b), poli(p)))
        return bissecao(a, p, poli, erro, i + 1)

    #   se o produto der menor que 0, saberemos que f(b) e f(p) tem sinais opostos entre si
    else:
        print("i-->{}\ta - {:.12f}\tb - {:.12f}\tp - {:.12f}\tf(a) - {:.12f}\tf(b) - {:.12f}\tf(p) - {:.12f}".format(i, a, b, p, poli(a), poli(b), poli(p)))
        return bissecao(b, p, poli, erro, i + 1)


def newton(x, f, d, erro, i):
    #   caso f(xk)<erro, já temos um x que satisfaça a condição/necessidade
    if abs(f(x)) < erro:
        print("i-->{}\tx - {:.10f}\tf(x) - {:.10f}\t".format(i, x, f(x)))
        return x

    #   caso contrario, continue calculando
    else:
        x = x - (f(x) / d(x))
        print("i-->{}\tx - {:.10f}\tf(x) - {:.10f}\t".format(i, x, f(x)))
        return newton(x, f, d, erro, i + 1)


def secante(x1, x0, f, erro, i):
    if abs(x1 - x0) < erro:
        return x0

    else:
        if i==0:
            print("i-->{}\tx - {:.15f}\tf(x) - {:.15f}\t".format(i, x0, f(x0)))
            print("i-->{}\tx - {:.15f}\tf(x) - {:.15f}\t".format(i+1, x1, f(x1)))
            i += 1

        else:
            aux = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0))
            print("i-->{}\tx - {:.15f}\tf(x) - {:.15f}\t".format(i, aux, f(aux)))
            x0 = x1
            x1 = aux

        return secante(x1, x0, f, erro, i+1)

main()