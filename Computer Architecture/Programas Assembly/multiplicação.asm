# para multiplicação usa-se mul

.text
main:

li $s0, 100 # insere o valor 10 no regitrador $s0
li $s1, 30 # insere o valor 5 no regitrador $s1
mul $s2,$s1,$s0 # multiplica o valor dos registradores $s0 e $s1 e insere no registrador $s2

la $a0, ($s2) #coloca o registrador $s2 para ser impresso
li $v0,1 #comando de impressão de inteiro na tela
syscall # efetua a chamada ao sistema

li $v0, 10 # comando de exit
syscall # efetua a chamada ao sistema