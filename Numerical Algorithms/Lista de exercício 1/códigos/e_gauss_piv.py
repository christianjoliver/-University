import math
import s_ret


def main():

	print( )

	O = int(input("Digite a ordem da matriz quadrada: "))
	m, c = s_ret.lê(O)

	print( )
	print( )

	m, c = gauss_p(m, O, c)

	print("Matriz com pivoteamento aplicado: ")
	print()
	imp(O, m)

	print("Vetor solucao: ")
	print()
	i_r(c, O)



def gauss_p(A, n, b):

#troca de linhas

	for k in range(n-1):

		maior = abs(A[k][k])
		r = k
		
		for i in range(k+1, n):

			if (abs(A[i][k])) > maior:
				
				maior = abs(A[i][k])
				r = i

		for i in range(0, n):

			v = A[k][i]

			A[k][i] = A[r][i]

			A[r][i] = v

		v = b[k]
		b[k] = b[r]	
		b[r] = v

		for i in range(k+1, n):
			
			m = ((-1)*A[i][k]) / A[k][k]

			for j in range(k, n):
				A[i][j] = A[i][j] + m * A[k][j]
			
			b[i] = b[i] + m*b[k]


	f = s_retr(n, A, b)

	return A, f 


def imp(O, matriz):

	for j in range(0, O):

			for k in range(0, O):
				print(f'[{matriz[j][k]:^5}] ', end='')
			print()

	print()
	print()
	print()



def i_r(x, i):
	
	for k in range(0, i):
			print(f' = [{x[k]:^5}]', end='')
			print()


def s_retr(n, L, b):

	x = [0 for f in range(0, n)]

	n = n-1

	x[n] = round((b[n]/L[n][n]), 10)

	for i in range(n-1, -1, -1):
		soma = 0

		for j in range(i, n+1):
			soma = soma + L[i][j] * x[j]

		x[i] = round(((b[i] - soma)/L[i][i]), 10)

	return x


if __name__  == '__main__':
	main()

