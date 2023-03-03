import math
import s_ret


def main():

	O = int(input("Digite a ordem da matriz quadrada: "))
	m, c = s_ret.lê(O)
	print()
	l, b = separa(O, m)
	print()

	
	print(" suup ")
	print()
	s_ret.imp(O, l, c)
	print()


	print("inf")
	print()
	s_ret.imp(O, b, c)

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


if __name__ == '__main__':
	main()