.data

.macro finalizarPrograma	# Nome da macro
	li $v0, 10	# Prepara para encerrar o pgorama
	syscall	# Executa a instrução

.end_macro


.macro soma (%n1, %n2)
	
	.data
	num1: .word %n1
	num2: .word %n2
	
	.text
	la $s0, num1
	la $s1, num2
	
	add $s2, $s0, $s1
	
	li $v0, 1  # impressao de um inteiro na tela
	la $a0, ($s2)
	syscall
.end_macro


.text
.globl principal

principal:
	soma(10, 5)
	finalizarPrograma
	

	
	
	
