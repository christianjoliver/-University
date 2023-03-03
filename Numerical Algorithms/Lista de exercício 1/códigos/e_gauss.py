import math
import s_ret

def main():

	print( )
	print( )

	O = int(input("Digite a ordem da matriz quadrada: "))

	m, c = s_ret.lê(O)

	print( )
	print( )
	print(" Matriz dada: ") 
	print( )

	s_ret.imp(O, m, c)

	m, c = gauss(m, O, c)

	print( )
	print( )

	print("Matriz Triangularizada com o método de Gauss: ")
	print( )

	s_ret.imp(O, m, c)

	m = s_ret.s_ret(O, m, c)

	print( )
	print( )
	print("Vetor Solução:")
	print( )
	s_ret.i_r(m, O)


def gauss(A, n, b):

	for k in range(n-1):

		for i in range(k+1, n):
			

			m = ((-1)*A[i][k]) / A[k][k]

			for j in range(k, n):

				A[i][j] = A[i][j] + m * A[k][j]
			
			b[i] = b[i] + m*b[k]


	s_ret.s_ret(n, A, b)

	return A, b

if __name__  == '__main__':
	main()
