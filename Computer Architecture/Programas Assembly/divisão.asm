# FALTA TERMINAR

# para divis�o usa-se sub
# registrador hi contera o resto da divis�o
# registrador lo contera o resultado da divis�o

.data
msg1: .asciiz "O resultado da divisao eh: "
msg2: .asciiz "\nO resto da divisao eh: "

.text
main:

li $s0, 100 	# insere o valor 100 no regitrador $s0
li $s1, 30 		# insere o valor 30 no regitrador $s1
div $s0, $s1 	# divide s0 por s1
mfhi $s2
mflo $s3

li $v0, 4		# Carrega a chamada de impress�o de uma string, carregando o valor 4 em v0
la $a0, msg1	# Carrega o endere�o da mensagem em a0.

li $v0, 1
la $a0, ($s3)
syscall			# Chamada da funcao carregada (impress�o)


li $v1, 4		# Carrega a chamada de impress�o de uma string, carregando o valor 4 em v0
la $a1, msg2	# Carrega o endere�o da mensagem em a0.
li $v1, 1
la $a1, ($s2)
syscall			# Chamada da funcao carregada (impress�o)


li $v0, 10 		# comando de exit
syscall 		# efetua a chamada ao sistema