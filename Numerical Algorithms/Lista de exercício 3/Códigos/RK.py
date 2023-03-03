def f(x, y):
    return -x/y


# Calcular y(1)

def main():
    x0 = 0
    y0 = 20
    h = 4
    x = 16
    xk = x0
    yk = y0

    while (xk < x):
        K1 = h * f(xk, yk)
        print("K1 = ", K1)
        K2 = h * f(xk + h / 2, yk + K1 / 2)
        print("K2 = ", K2)
        K3 = h * f(xk + 1 / 2 * h, yk + 1 / 2 * K2)
        print("K3 = ", K3)
        K4 = h * f(xk + h, yk + K3)
        print("K4 = ", K4)

        yk = yk + (1 / 6) * (K1 + 2 * K2 + 2 * K3 + K4)
        print("yk = ", yk)
        print("yk = ", xk)
        xk = xk + h
        print()

    print(yk)


main()