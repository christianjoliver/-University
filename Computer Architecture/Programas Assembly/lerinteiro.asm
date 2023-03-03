.data
msg1: .asciiz "Digite o primeiro numero: "
msg2: .asciiz "Digite o segundo numero: "
msg3: .asciiz "O resultado da multiplicacao eh: "

.text

main:
li $v0, 4  		# prepara para imprimir uma string
la $a0, msg1 	# coloca msg1 em $a0
syscall

li $v0, 5		# codigo oara ler inteiro digitado
syscall 

move $s0, $v0

li $v0, 4  		# prepara para imprimir uma string
la $a0, msg2 	# coloca msg2 em $a0
syscall

li $v0, 5		# codigo oara ler inteiro digitado
syscall

move $s1, $v0

li $v0, 4  		# prepara para imprimir uma string
la $a0, msg3 	# coloca msg3 em $a0
syscall

mul $s2, $s1, $s0 #multiplicacao

li $v0, 1  		# prepara para imprimir um inteiro
la $a0, ($s2) 	# coloca resultado em $a0
syscall


li $v0, 10 # Encerra o programa
syscall # Chamada da funcao carregada (Fechamento do programa)
