.data

.macro finalizarPrograma	# Nome da macro
	li $v0, 10	# Prepara para encerrar o pgorama
	syscall	# Executa a instrução

.end_macro

.macro printf (%str) # Nome da macro. %str é a string passada como parâmetro

	.data
	msg: .asciiz %str 	# Define o valor da variavel msg
	.text
	li $v0, 4
	la $a0, msg
	syscall
	
.end_macro

.text
.globl principal

principal:
printf("Ola Mundo\n")
finalizarPrograma
