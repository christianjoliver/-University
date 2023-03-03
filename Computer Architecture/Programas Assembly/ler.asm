.data
nome: .space 40 # nome digitado pelo usuario
msg1: .asciiz "Digite o seu nome: "
msg2: .asciiz "Seja bem vindo "

.text

main:
li $v0, 4  		# prepara para imprimir uma string
la $a0, msg1 	# coloca msg em $a0
syscall

li $v0, 8		# cpidugi oara ler string digitada
la $a0, nome	# var onde sera salva
la $a1, 40		# tamanho maximo
syscall

li $v0, 4  		# prepara para imprimir uma string
la $a0, msg2 	# coloca msg em $a0
syscall

li $v0, 4  		# prepara para imprimir uma string
la $a0, nome 	# coloca nome em $a0
syscall


li $v0, 10 # Encerra o programa
syscall # Chamada da funcao carregada (Fechamento do programa)