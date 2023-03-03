import math
import copy



def main():
  
  x = 0
  O = int(input("Digite a ordem da matriz quadrada: "))
  m, c = lê(O)


  m1 = [[0 for f in range(O)] for j in range(O)]
  m2 = [[0 for f in range(O)] for j in range(O)]
  m3 = [[0 for f in range(O)] for j in range(O)]

  c1 = [0 for f in range(O)]
  c2 = [0 for f in range(O)]
  c3 = [0 for f in range(O)]


  for i in range(O):
  	c1[i] = c[i]
  	c2[i] = c[i]
  	c3[i] = c[i]
  	for j in range(O):
  		m1[i][j] = m[i][j]
  		m2[i][j] = m[i][j]
  		m3[i][j] = m[i][j]



  print( )
  print( )

  print("Matriz dada: ")
  imp(O, m, c)
 

  chama_gauss(m1, c1, O)

  chama_gauss_piv(m2, c2, O)
 
  chama_decomposicaoLU(m3, c3, O)


################################################################################


def lê(i):

	mat = [[0 for l in range(i)] for c in range(i)]
	
	for j in range(0, i):

		for k in range(0, i):

			mat[j][k] = int(input(f"Valor da coordenada [{j}, {k}]: "))

	
	cof = [0 for f in range(i)]

	for v in range(0,i):

		cof[v] = int(input(f"Valor da coordenada [{v}, 0] da matriz dos cofatores: "))

	return (mat, cof)
 

################################################################################


def chama_gauss_piv(m, c, O):

	print( )
	print( )

	m, c = gauss_p(m, O, c)

	print("Matriz com pivoteamento aplicado: ")
	print()
	imp_piv(O, m)

	print("Vetor solucao: ")
	print()
	i_r(c, O)
 

################################################################################


def chama_gauss(m, c, O):

	print( )
	print( )

	m, c = gauss(m, O, c)

	print("Matriz Triangularizada com o método de Gauss: ")
	print( )

	imp(O, m, c)

	m = s_ret(O, m, c)

	print("Vetor Solução:")
	print( )
	i_r(m, O)
 

################################################################################


def chama_decomposicaoLU(m, c, O):

	m, t = d_LU(m, O)

	print()
	print()
	print("Matriz com a decomposição aplicada: ")
	print()

	imp_dLU(O, m)

	t_sup, t_inf = separa(O, m)

		
	t = org_p(t, O)

	

	c = multiplica(t, c, O)

	

	c = s_suc(O, t_inf, c)

	

	c = s_ret(O, t_sup, c)

	print("Matriz X resultante: ")
	print()

	i_r_dLU(c, O)
 

################################################################################


def imp_piv(O, matriz):

	for j in range(0, O):

			for k in range(0, O):
				print(f'[{matriz[j][k]:^5}] ', end='')
			print()

	print()
	print()
	print()


################################################################################

def imp(O, matriz, cofator):

	for j in range(0, O):

			for k in range(0, O):

				print(f'[{matriz[j][k]:^5}] ', end='')
			print(f' = [{cofator[j]:^5}]', end='')
			print()

	print()
	print()
	print()


################################################################################


def i_r(x, i):
	
	for k in range(0, i):

			print(f' = [{x[k]:^5}]', end='')
			print()
   

################################################################################


def separa(n, mat):

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
   


################################################################################


def org_p(m, n):

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


################################################################################


def multiplica(m1, m2, O):

	aux = [0 for f in range(O)]

	for i in range(O):

		for j in range(O):

			aux[i] += m1[i][j] * m2[j] 

	return aux



################################################################################


def i_r_dLU(x, i):
	
	for k in range(0, i):

			print(f'x{k+1} = [{x[k]:^5}]', end='')
			print()
   

################################################################################


def imp_dLU(O, matriz):

	for j in range(0, O):

			for k in range(0, O):

				print(f'[{matriz[j][k]:^5}] ', end='')
			print()

	print()
	print()
	print()
 

################################################################################



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

      # ajuste do vetor de apoio à matriz triangular (permutação de linhas)

		if r != k:

			v = p[k]

			p[k] = p[r]

			p[r] = v

      # permutação das linhas

			for j in range(n):

				v = A[k][j]

				A[k][j] = A[r][j]

				A[r][j] = v

    # Gauss

		for i in range(k+1, n):

			m = A[i][k]/A[k][k]

			A[i][k] = m

			for j in range(k+1, n):
				A[i][j] = A[i][j] - m * A[k][j]

	return A, p


################################################################################


def gauss_p(A, n, b):

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



################################################################################



def gauss(A, n, b):

	for k in range(n-1):

		for i in range(k+1, n):
			

			m = ((-1)*A[i][k]) / A[k][k]

			for j in range(k, n):

				A[i][j] = A[i][j] + m * A[k][j]
			
			b[i] = b[i] + m*b[k]


	s_ret(n, A, b)

	return A, b


################################################################################


def s_suc(n, L, b):

	x = [0 for f in range(0, n)]

	x[0] = round((b[0]/L[0][0]), 10)
	i = 1
	j = 0

	for i in range(i, n):
		soma = 0

		for j in range(j, i):
			soma = soma + L[i][j] * x[j]

		x[i] = round(((b[i] - soma)/L[i][i]), 10)

	return x


################################################################################

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


################################################################################


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


################################################################################


if __name__  == '__main__':
  main()