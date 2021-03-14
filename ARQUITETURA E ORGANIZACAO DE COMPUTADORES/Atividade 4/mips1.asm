	.data 
a:	.word 1, 2, 5, 1, 5, 2
	.text 
	.globl main 
		
main:	
	addi $t1, $0, 50
	la $s0, a

	# t1 = i
	# s2 = result
	# s0 = MemArray 
LOOP: 	lw $s1, 0($s0)
 	add $s2, $s2, $s1 
 	lw $s1, 4($s0)
 	add $s2, $s2, $s1
 	addi $s0, $s0, 8 
 	subi $t1, $t1, 1 
 	bne $t1, $0, LOOP
	

	
	
	
