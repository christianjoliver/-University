import math
import timeit

def main():
	i = int(input("Digite a ordem da matriz: "))

	m, b, erro = lê(i)

	if c_lines(m, i):
		ini = timeit.default_timer()
		g_jac(m, b, erro)
		fim = timeit.default_timer()
		

	else:
		print("O critério de linhas não é estabelecido. Deseja continuar? s/n ")
		
		esc = str(input())

		if esc=='s':
			ini = timeit.default_timer()
			g_jac(m, b, erro)
			fim = timeit.default_timer()

		else: 
			print("Fim")


	print()
	print("Tempo gasto: ", (fim - ini))


def c_lines(m, o):

	ver = 1;

	for i in range(o):

		soma = 0

		for j in range(o):

			if i!=j:

				soma += abs(m[i][j])

		if soma > abs(m[i][i]):

			ver = 0

	return ver



def g_jac(m, b, erro):

	O = len(m)
	e = 1
	x0 = [0 for i in range(O)] 
	aux = [0 for i in range(O)]
	
		#	definindo x0

	for i in range(O):
		x0[i] = (b[i]/m[i][i])

	# 	isolando xk e calculando o valor de X

	while e > erro:

		for i in range(O):

			x = b[i]

			for j in range(O):

				if i!=j:

					x -= m[i][j] * x0[j]

			x /= m[i][i]

			aux[i] = x

		#	calculando o erro

		maior = 0

		for k in range(O):

			h = abs(aux[k] - x0[k])

			if h > maior: 

				maior = h

		e = maior/abs(max(aux, key=float))

		#	atualizando x0 para a prox iteracao

		for f in range(O):
			x0[f] = aux[f]
		
	print()
	print()
		
	for i in range(O):
		print(f' = [{round(x0[i], 5):^13}]', end='')
		print()
	


def lê(i):

	mat = [[0 for l in range(i)] for c in range(i)]
	
	for j in range(0, i):

		for k in range(0, i):

			mat[j][k] = float(input(f"Valor da coordenada [{j}, {k}]: "))

	
	cof = [0 for f in range(i)]

	for v in range(0,i):

		cof[v] = float(input(f"Valor da coordenada [{v}, 0] da matriz dos cofatores: "))

	e = float(input("Digite o erro: "))

	return (mat, cof, e)


if __name__ == '__main__':
	main()
