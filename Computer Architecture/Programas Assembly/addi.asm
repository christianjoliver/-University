.text

############ usando addi ###########################

addi $s0, $zero, 5 # soma 5 a $zero e atribui a $s0
addi $s1, $s0, 10 # soma 10 a $zero e atribui a #s2.
addi $s2, $s1, 20 # soma 20 a $zero e atribui a #s2.

############# como seria normalmente ###############
# li $s0, 10
# li $s1, 5
# li $s2, 20
# add $s3, $s2, $s1
# add $s4, $s3, $s2


li $v0, 1
la $a0, ($s2)
syscall

