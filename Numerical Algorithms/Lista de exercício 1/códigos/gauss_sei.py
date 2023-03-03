import math
import timeit


def main():
	i = int(input("Digite a ordem da matriz: "))

	m, b, erro = lê(i)


	if c_sassen(m, i):
		ini = timeit.default_timer()
		g_sei(m, b, erro)
		fim = timeit.default_timer()
		print()
		print("Tempo gasto: ", (fim - ini))
		

	else:
		print("O critério de sassenfeld não é estabelecido. Deseja continuar? s/n ")
		
		esc = str(input())

		if esc=='s':
			ini = timeit.default_timer()
			g_sei(m, b, erro)
			fim = timeit.default_timer()
			print()
			print("Tempo gasto: ", (fim - ini))

		else: 
			print("Fim")



def c_sassen(m, o):

	lt = []

	for i in range(o):

		aux = 0

		for j in range(o):

			if (i!=j and i==0) or i<j:

				aux += (m[i][j])

			elif i!=j and i!=0:

				aux += (m[i][j] * lt[j])

		aux /= (m[i][i])
		lt.append(aux)

	mc = max(lt)

	if mc<1:
		return 1
	else:
		return 0



def g_sei(m, b, erro):

	O = len(m)
	e = 1
	x0 = [0 for i in range(O)] 
	aux = [0 for i in range(O)]


	# 	isolando xk e calculando o valor de X

	while e > erro :

		for i in range(O):

			x = b[i]

			for j in range(O):

				if i!=j:

					x -= m[i][j] * x0[j]

			x /= m[i][i]

			x0[i] = x

		#	calculando o erro

		maior = 0

		for k in range(O):

			h = abs(x0[k] - aux[k])

			if h > maior: 

				maior = h

		e = maior/abs(max(x0, key=float))

		#	atualizando aux para a prox iteracao

		for f in range(O):
			aux[f] = x0[f]

		
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
