.data

msg: .asciiz "hoopa"

.text

.globl principal  # Define o que sera executado primeiro, como se fosse uma main.

principal:


li $v0, 4	# Carrega a chamada de impress�o de uma string, carregando o valor 4 em v0

la $a0, msg	# Carrega o endere�o da mensagem em a0.

syscall	# Chamada da funcao carregada (impress�o)

li $v0, 10 # Encerra o programa

syscall # Chamada da funcao carregada (Fechamento do programa)

