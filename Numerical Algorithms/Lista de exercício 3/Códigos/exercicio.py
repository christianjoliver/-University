from math import *

def f(x, y):

    return 4-2*x


def main():

    x0 = 0
    y0 = 2
    p = 5
    h = 0.5

    calcula(x0, y0, h, p, 0)


def calcula(x0, y0, h, p, cont):

    if (x0+h)==p+h:
        print("x{} = {}".format(cont, x0))
        print("y{} = {}".format(cont, y0))

    else:
        x1 = x0 + h
        y1 = y0 + h * (f(x0, y0) + f(x0+h, y0+h*f(x0, y0)))
        print("x{} = {}".format(cont, x0))
        print("y{} = {}".format(cont, y0))
        return calcula(x1, y1, h, p, cont+1)

main()