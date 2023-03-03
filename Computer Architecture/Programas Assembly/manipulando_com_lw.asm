.data
idade: .word 21
nome: .asciiz "Christian Oliveira\n"


.text

main:

lw $t0, idade		# Carrega o conteudo de idade no reg $t0 (lw para inteiro)
la $t1, nome		# Carrega o conteudo de nome no reg $t1	 (la para string)


li $v0, 4  		# prepara para imprimir uma string
la $a0, ($t1) 	# coloca msg1 em $a0
syscall


li $v0, 1 		# Prepara para imprimmir um inteiro
la $a0, ($t0)   #carrega o valor de $t0 em $a0.
syscall


li $v0, 10 # Encerra o programa
syscall # Chamada da funcao carregada (Fechamento do programa)