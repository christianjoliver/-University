.data  # Diretiva usada para declarar as variaveis ou constantes

msg: .asciiz "Hellow"	# Mensagem propriamente dita

.text	# Diretiva usada para conter o codigo em si

li $v0, 4	# Carrega a chamada de impress�o de uma string

la $a0, msg	# Carrega o endere�o da mensagem em a0

syscall	# Chamada da funcao carregada (impress�o)

li $v0, 10 # Encerra o programa

syscall # Chamada da funcao carregada (Fechamento do programa)