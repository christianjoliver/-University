from math import *

def funcao(x, y):

    return 4-2*x


def main():
    x0 = 0
    y0 = 2
    m = 10
    a = 0
    b = 5

    h = (b - a)/m

    calcula(x0, y0, 0, m, h)


def calcula(x0, y0, cont, m, h):

    if(cont == m):

        print("x{} = {}".format(cont, x0))
        print("y{} = {}".format(cont, y0))

    else:
        x1 = x0 + h
        y1 = y0 + h*funcao(x0, y0)
        print("x{} = {}".format(cont, x0))
        print("y{} = {}".format(cont, y0))

        return calcula(x1, y1, cont+1, m, h)

main()