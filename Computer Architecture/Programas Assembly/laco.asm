.data
################################## terminar ###############################
.macro encerra
	li $v0, 10 		# comando de exit
	syscall 		# efetua a chamada ao sistema
	.end_macro
	

.macro lerint
	li $v0, 5
	syscall
.end_macro 


.text
.globl main

main:
	lerint
	move $s0, $v0
	j while
	
	
while:
	bgt $t0, $s0, fim        
    move $v0, $t0
    li $v1, 1  		
	la $a0, ($v0)
	syscall         
    addiu $t0, $t0, 1
    j while
    
	
fim:
	encerra
	