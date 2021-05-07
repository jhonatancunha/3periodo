	# Compilando uma atribuição quando um operando está na memória - página 65
	# Adicionado valores nos registradores e vetor do exemplo contido no livro
	.data 
	.text 
	.globl main 
		
main:		
	lw $t0,0($zero) # endereçamento do byte na instrução load word para selecionar a[8]
	addi $s1,$t0, 3 # registrador $s1 recebe h + a[8] 
	sw $s1, 4($zero)
	j teste
	
exit: j exit	
	
	
teste:  lw $t4, 4($zero)
	addi $t4, $zero, 4
	j exit