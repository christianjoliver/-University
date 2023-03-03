
class Poli:
	def __init__(self, grau, coeficiente):
		self.grau = grau
		self.coeficiente = coeficiente			


def main():

	x = [0, 1, 2]
	y = [0, 7, 50]
	a = lagrange2(x, y)

	print()
	imprimePoly(a)
	print()


def lagrange2(x, y):

	tam = len(x)

	soma = [Poli(-1, 0)]

	pol = [Poli(1, 1)]

	for i in range(tam):

		L = [Poli(0, 1)]

		for j in range(tam):

			if i!=j:

				numerador = s_poli(copiaLista(pol), [Poli(0, (-1)*x[j])])
				
				denominador = x[i] - x[j]

				s = d_poli(numerador, denominador)

				L = m_poli(L, s)

		soma = s_poli(soma, m_poli([Poli(0, y[i])], L))

	return soma
	

def d_poli(x, n):

	r = x[:]

	for i in range(len(x)):

		r[i].coeficiente /= n

	return r


def lagrange(x, y):
	
	soma = 0
	pol = []

	for i in range(tam):

		L = 1

		for j in range(tam):

			if i!=j:

				L = L * (p - x[j])/(x[i] - x[j])

		soma += y[i] * L
	
	return soma


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
	

def copiaLista(x):
    copia = []
    n = len(x)
    for i in range(0,n):
        coef = x[i].coeficiente
        grau = x[i].grau
        aux = Poli(grau,coef)
        copia += [aux]
    return copia	


def busca(x, e):
	for i in range(len(x)):
		if(x[i].grau==e):
			return i
	return -1

if __name__ == '__main__':
	main()