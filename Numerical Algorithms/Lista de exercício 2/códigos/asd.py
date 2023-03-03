from sympy import *

class Polynomial:

    def __init__(self, *coeficiente):
        self.coeficiente = list(coeficiente)

    def __call__(self, x):
        #   metodo da classe Polynomial para retornar o resultado do polinomio aplicado a um x

        result = 0
        tam = len(self.coeficiente)+1

        for i, coef in enumerate(self.coeficiente[::-1]):
            result += coef * (x ** i)

        return result

    def printa(self):
        #   metodo da classe Polynomial para printar o polinomio usando o Sympy
        grau = len(self.coeficiente) - 1
        x = Symbol('x')
        init_printing(pretty_print=true)
        result = self.coeficiente[0] * x**grau

        for i in range(1, len(self.coeficiente) - 1):

            coef = self.coeficiente[i]
            if coef < 0:
                result +=  coef * x**(grau - i)
            else:
                result += coef * x**(grau - i)

        if self.coeficiente[-1] < 0:
            result += -self.coeficiente[-1]
        else:
            result += (self.coeficiente[-1])

        pprint(result)


def main():
    a = Polynomial(1, 2, 3, 4)
    a.printa()

    print(a(1))

    # x = Symbol('x')


main()