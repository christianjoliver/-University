import math

def main():
	O = int(input("Digite a ordem da matriz quadrada: "))
	m, c = lê(O)
	imp(O, m, c)

	i_r(s_ret(O, m, c), O)

	

def s_ret(n, L, b):

	x = [0 for f in range(0, n)]

	n = n-1

	x[n] = round((b[n]/L[n][n]), 10)

	for i in range(n-1, -1, -1):
		soma = 0

		for j in range(i, n+1):
			soma = soma + L[i][j] * x[j]

		x[i] = round(((b[i] - soma)/L[i][i]), 10)

	return x



def lê(i):

	mat = [[0 for l in range(i)] for c in range(i)]
	
	for j in range(0, i):

		for k in range(0, i):

			mat[j][k] = float(input(f"Valor da coordenada [{j}, {k}]: "))

	
	cof = [0 for f in range(i)]

	for v in range(0,i):

		cof[v] = int(input(f"Valor da coordenada [{v}, 0] da matriz dos cofatores: "))

	return (mat, cof)



	
def imp(O, matriz, cofator):

	for j in range(0, O):

			for k in range(0, O):

				print(f'[{matriz[j][k]:^5}] ', end='')
			print(f' = [{cofator[j]:^5}]', end='')
			print()

	print()
	print()
	print()



def i_r(x, i):
	
	for k in range(0, i):

			print(f' = [{x[k]:^5}]', end='')
			print()




if __name__  == '__main__':
	main()
