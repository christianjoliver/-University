import math
import s_ret
import s_suc


def main():

	print( )

	O = int(input("Digite a ordem da matriz quadrada: "))

		# lê e armazena uma matriz e seus cofatores

	m, c = s_ret.lê(O)

	print( )
	print( )
	print("Matriz dada: ")
	s_ret.imp(O, m, c)

		
		# aplica a decomposição LU e armazena seus resultados

	m, t = d_LU(m, O)

		# chamada da função que separa e armazena a matriz 'm' em 2 subdivisões 

	print()
	print()
	print("Matriz com a decomposição aplicada: ")
	print()

	imp(O, m)

	t_sup, t_inf = separa(O, m)

		# funcao para organizar a matriz identidade de acordo com as permutações

	t = org_p(t, O)

		# multiplicação Pb

	c = multiplica(t, c, O)

		# encontrando Y

	c = s_suc.s_suc(O, t_inf, c)

		#encontrando X

	c = s_ret.s_ret(O, t_sup, c)

	print("Matriz X resultante: ")
	print()

	i_r(c, O)

	

def d_LU(A, n):


	p = [0 for f in range(n)] 

		
	for i in range(n):

		p[i] = i

		# move o pivo

	for k in range(n-1):

		pi = A[k][k]

		r  = k

		# move coluna

		for i in range (k+1, n):

			# verifica se o numero abaixo do pivo eh maior que ele

			if abs(A[i][k]) > abs(pi):

				pi = A[i][k]
				r = i


		if pi == 0:

			break

		if r != k:

			v = p[k]

			p[k] = p[r]

			p[r] = v

			for j in range(n):

				v = A[k][j]

				A[k][j] = A[r][j]

				A[r][j] = v

		for i in range(k+1, n):

			m = A[i][k]/A[k][k]

			A[i][k] = m

			for j in range(k+1, n):
				A[i][j] = A[i][j] - m * A[k][j]

	return A, p



def org_p(m, n):

		# funcao que organiza P

	aux = [[0 for f in range(n)] for g in range(n)]

	for i in range(n):
		aux[i][i] = 1


	for i in range(n):

			if m[i] != i:

				aux[i][i] = 0

				aux[i][m[i]] = 1

				aux[m[i]][i] = 1

				aux[m[i]][m[i]] = 0

				f = m[i]

				r = m[f]

				m[i] = r

				m[f] = f 

	return aux


def separa(n, mat):

	# funcao que separa a parte triangular inferior e superior de uma matriz

	inf = [[0 for f in range(n)] for g in range(n)]

	sup = [[0 for f in range(n)] for g in range(n)]

	

	for i in range(n-1, -1, -1):

		for j in range(i, -1, -1):

			if i==j:
				inf[i][j] = 1

			else:
				inf[i][j] = mat[i][j] 

	for i in range(n):

		for j in range(i, n):

			if i==j:
				sup[i][j] = mat[i][j]

			else:
				sup[i][j] = mat[i][j]


	return sup, inf



def multiplica(m1, m2, O):

	# multiplica P x b

	aux = [0 for f in range(O)]

	for i in range(O):

		for j in range(O):

			aux[i] += m1[i][j] * m2[j] 

	return aux


def i_r(x, i):
	
	for k in range(0, i):

			print(f'x{k+1} = [{x[k]:^5}]', end='')
			print()


def imp(O, matriz):

	for j in range(0, O):

			for k in range(0, O):

				print(f'[{matriz[j][k]:^5}] ', end='')
			print()

	print()
	print()
	print()


if __name__  == '__main__':
	main()
