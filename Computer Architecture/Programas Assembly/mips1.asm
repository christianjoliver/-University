
.macro fim # Inicio do amcro que enceessa o programa.
	li $v0, 10 # Configura o serviço para o fim do programa, 10 é o valor que v0 deve receber para fechar um programa - Exit.
	
	syscall # Executa a instrução feita na função
	
.end_macro # Fim da macro



# Para Strings usa-se .asciiz
msg: .asciiz "Hellow"

# Para Int, usa-se .word
idade: .word 123

# Float usa-se .float
salario: .float 10500.35

# Char, usa-se .byte
sexo: .byte 'M'

