import math





def main():

	print("Poli 1")
	print()

	x = lePolinomio()
	print()
	#imprimePoly(x)
	print()

	print("Poli 2")
	print()

	y = lePolinomio()
	print()
	#imprimePoly(y)

	print()
	print()

	imprimePoly(m_poli(copiaLista(x), copiaLista(y)))
	



class Poli:
	def __init__(self, grau, coeficiente):
		self.grau = grau
		self.coeficiente = coeficiente		


def copiaLista(x):
    copia = []
    n = len(x)
    for i in range(0,n):
        coef = x[i].coeficiente
        grau = x[i].grau
        aux = Poli(grau,coef)
        copia += [aux]
    return copia


def lePolinomio():
    print("Digite o grau do polinomio:",end = "")
    n = int(input())
    x = []
    for i in range(n, -1, -1):

        print("Digite o coeficiente do elemento de grau {}:".format(i),end = "")
        coeficiente = float(input())
        aux = Poli(i,coeficiente)
        x += [aux]

    return x


def imprimePoly(x):
	n = len(x)

	for i in range(n):

		if(x[i].coeficiente != 0):

			if (x[i].grau == 0):

				if(x[i].coeficiente<0):
					print("- {}".format(abs(x[i].coeficiente)), end="")

				else:
					print("+ {}".format(x[i].coeficiente), end="")

			else:

				if(x[i].coeficiente < 0):
					print("- {}x^{} ".format(abs(x[i].coeficiente),x[i].grau),end = "")

				else:
					print("+ {}x^{} ".format(x[i].coeficiente,x[i].grau),end = "")



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
	
	if len(x)==0:
		return y

	if len(y)==0:
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
		if(x[i].grau==e):
			return i
	return -1

if __name__ == '__main__':
	main()
	