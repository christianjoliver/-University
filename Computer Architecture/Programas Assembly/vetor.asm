.data
vetor: .space 12
novaLinha: .asciiz "\n"


.text
addi $s0, $zero, 5 # soma 5 a $zero e atribui a $s0
addi $s1, $s0, 10 # soma 10 a $zero e atribui a #s2.
addi $s2, $s1, 15 # soma 20 a $zero e atribui a #s2.


# Index = $t0
addi $t0, $zero, 0 # Como se fosse a variavel i do vetor


sw $s0, vetor($t0) # Insere $s0 na posição 0 do vetor
addi $t0, $t0, 4 #incrementa i em 4
sw $s1, vetor($t0) # insere $s1 na posição 4 do vetor
addi $t0, $t0,  4 #incrementa i em 4
sw $s2, vetor($t0) #insere $s2 na posição 8 do vetor
addi $t0, $t0,  4 #incrementa i em 4  


# zerar a variavel contador
addi $t0, $zero, 0


# carregar dois valores na memporia principal
lw $t6, vetor ($t0)#carrega o primeiro elemento em $t6
addi $t0, $t0, 4
lw $t7, vetor($t0) #carrega o segundo elemento em $t7


#imprime na tela o primeiro elemento

li $v0, 1
addi $a0, $t6, 0
syscall



#########################333 terminar 
