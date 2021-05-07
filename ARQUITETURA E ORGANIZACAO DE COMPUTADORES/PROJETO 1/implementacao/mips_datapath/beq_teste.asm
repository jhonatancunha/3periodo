	.data 
	.text 
	.globl main 
main:	
	addi $t2, $zero, 1
	addi $t3, $zero, 1
	beq $t3, $t2, jumpado
	
exit: j exit 

jumpado: addi $t3, $zero, 10
