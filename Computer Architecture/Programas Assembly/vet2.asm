
########################################33    conferir o que esta errado ########################

.data
vetor: .space 12
novaLinha: .asciiz "\n"


.macro encerra
	li $v0, 10 		# comando de exit
	syscall 		# efetua a chamada ao sistema
	.end_macro
	
	
.text
addi $s0, $zero, 5 
addi $s1, $zero, 6 
addi $s2, $zero, 7 

# Index = $t0
addi $t0, $zero, 0 # Como se fosse a variavel i do vetor


sw $s0, vetor($t0) # Insere $s0 na posição 0 do vetor
addi $t0, $t0, 4 #incrementa i em 4
sw $s1, vetor($t0) # insere $s1 na posição 4 do vetor
addi $t0, $t0,  4 #incrementa i em 4
sw $s2, vetor($t0) #insere $s2 na posição 8 do vetor


# zerar a variavel contador
addi $t0, $zero, 0

while:

	beq $t0, 12, fim
	
	lw $t6, vetor($t0)
	
	addi $t0, $t0, 4
	
	# imprime  numero atual
	
	li $v0, 1
	move $a0,  $t6
	syscall
	
	li $a0, 4
	la $a0, novaLinha
	syscall


fim:
	encerra