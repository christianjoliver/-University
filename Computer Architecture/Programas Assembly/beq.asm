.data

.macro encerra
	li $v0, 10 		# comando de exit
	syscall 		# efetua a chamada ao sistema
	.end_macro
	
.macro printf (%str)
	.data
	msg: .asciiz %str
	.text
	li $v0, 4
	la $a0, msg
	syscall
.end_macro 

	
	
.text

	li $s0, 10
	li $s1, 50
	li $s2, 10
	
.globl main
main:
	ble $s0, $s1, iguais
	printf("\nOs numeros sao DIFERENTES")
	encerra

iguais:
	ble $s1, $s2, final
	printf("\nOs numeros sao DIFERENTES")
	encerra

final:
	printf("\nOs numeros sao IGUAIS")
	encerra