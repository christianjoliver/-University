.data
idade: .word 0
msg1: .asciiz "Digite o um inteiro: "


.text

main:

li $v0, 5		# codigo oara ler inteiro digitado
syscall

move $t0, $v0

sw $t0, idade

li $v0, 1  		# prepara para imprimir um inteiro
lw $a0, idade 	# coloca resultado em $a0
syscall

li $v0, 10 # Encerra o programa
syscall # Chamada da funcao carregada (Fechamento do programa)