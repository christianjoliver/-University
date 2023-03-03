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

        if grau!=0:
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
        x = int(input("Digite o coeficiente do monomio de grau {}: ".format(i)))
        p.add(x)
    a = int(input("Digite o limitante inferior: "))
    b = int(input("Digite o limitante superior: "))
    print()
    print("\t\tPolinomio digitado: ")
    display(p.printa())

    while (True):
        print("-" * 41)
        print("|\t\t1 - Trapezios\t\t\t\t\t|")
        print("|\t\t2 - 1/8 de Simpson\t\t\t\t|")
        print("|\t\t3 - 3/8 de Simpson\t\t\t\t|")
        print("-" * 41)
        metodo = int(input("\tDigite o metodo desejado ou 0 para sair: "))




        if metodo == 1:
            op = int(input("Digite o número de intervalos (diferente de zero): "))
            while(op<=0):
                op = int(input("Digite um número de intervalos válido: "))
            print()
            print("Integral encontrada: ", trapezios(a, b, op, p))
            print()

        elif metodo == 2:
            op = int(input("Digite o número de intervalos (multiplo de dois e diferente de zero): "))
            while (op % 2 != 0):
                op = int(input("Digite um número de intervalos válido: "))
            print()
            print("Integral encontrada: ", um_terco(a, b, op, p))
            print()

        elif metodo == 3:
            op = int(input("Digite o número de intervalos (multiplo de tres e diferente de zero): "))
            while (op % 3 != 0):
                op = int(input("Digite um número de intervalos válido: "))
            print()
            print("Integral encontrada: ", tres_oitavos(a, b, op, p))
            print()
        else:
            break





def trapezios(a, b, m, f):
    h = (b-a)/m
    j = a+h
    soma = 0
    erro = []
    d = (f.derivative()).derivative()
    cont = 0
    soma += f(a)
    soma += f(b)

    erro.append(abs(d(a)))
    erro.append(abs(d(b)))

    while(cont < m-1):

        soma += 2*f(j)
        erro.append(abs(d(j)))
        cont+=1
        j += h

    e = -1*(b-a)**3/(12*m**2) * d(max(erro))

    return (h/2)*soma


def um_terco(a, b, m, f):
    h = (b - a)/m
    j = a+h
    soma = 0
    cont = 1
    erro = []
    d = (((f.derivative()).derivative()).derivative()).derivative()
    soma += f(a)
    soma += f(b)
    erro.append(abs(d(a)))
    erro.append(abs(d(b)))

    while(cont <= m-1):

        if (cont % 2) != 0:
            soma += 4 * f(j)
        else:
            soma += 2*f(j)

        erro.append(abs(d(j)))
        cont+=1
        j+=h

    e = -1*(b-a)**5/(180*m**4) * d(max(erro))

    return (h/3)*soma


def tres_oitavos(a, b, m, f):
    h = (b - a) / m
    j = a + h
    soma = 0
    cont = 1
    erro = []
    d = (((f.derivative()).derivative()).derivative()).derivative()
    soma += f(a)
    soma += f(b)
    erro.append(abs(d(a)))
    erro.append(abs(d(b)))

    while (cont <= m-1):

        if (cont % 3) == 0:
            soma += 2 * f(j)

        else:
            soma += 3 * f(j)

        erro.append(abs(d(j)))
        cont += 1
        j += h

    e = -1 * (b - a) ** 5 / (80 * m ** 4) * d(max(erro))

    return (3*h / 8) * soma

main()