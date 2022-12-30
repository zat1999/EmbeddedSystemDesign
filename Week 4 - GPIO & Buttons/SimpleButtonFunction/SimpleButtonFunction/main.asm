;
; SimpleButtonFunction.asm
;
; Created: 30/10/2022 4:11:24 PM
; Author : Aizat
;

start:
	sbi ddrb, 0 
	sbi ddrb, 1
	;sets the data direction for portBpin0+1 as outputs

	cbi ddrb, 2
	cbi ddrb, 3
	;sets the data direction for portBpin2+3 as inputs

	sbi portb, 2
	sbi portb, 3
	;enableds pull-up resistor

loop:
	sbis pinb, 2	;when button at pin2 pressed, runs below instruction
		RJMP L1

	sbis pinb, 3	;likewise
		RJMP L2

	cbi portb, 0	;if no buttons pressed, set output to low
	cbi portb, 1
	rjmp loop		;loop back
	
	L1:
		sbi portb, 0
		;cbi portb, 1
		rjmp loop
	 
	L2:
		sbi portb, 1
		;cbi portb, 0
		rjmp loop

	 