
.macro fim # Inicio do amcro que enceessa o programa.
	li $v0, 10 # Configura o servi�o para o fim do programa, 10 � o valor que v0 deve receber para fechar um programa - Exit.
	
	syscall # Executa a instru��o feita na fun��o
	
.end_macro # Fim da macro



# Para Strings usa-se .asciiz
msg: .asciiz "Hellow"

# Para Int, usa-se .word
idade: .word 123

# Float usa-se .float
salario: .float 10500.35

# Char, usa-se .byte
sexo: .byte 'M'

