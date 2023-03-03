import math

def main():

    a, b, cond = troca_sinal(1)
    print("\n\n")
    print("valor de A: ", a)
    print("valor de B: ", b)

def funcao(x):

    return math.e**(-1*x) + (x**2) - 10

def troca_sinal(z):
    if z == 0:
        a = -0.05
        b = 0.05
    else:
        a = 0.95 * z
        b = 1.05 * z
    iter = 0
    aureo = 2/(math.sqrt(5)-1)
    fa = funcao(a)
    fb = funcao(b)

    while(True):

        if fa * fb <=0 or iter>=20:
            break
        iter += 1
        if abs(fa) < abs(fb):
            a -= aureo * (b-a)
            fa = funcao(a)
        else:
            b += aureo * (b-a)
            fb = funcao(b)

    if fa * fb <= 0:
        cond = 0

    else:
        cond = 1

    return a, b, cond

main()