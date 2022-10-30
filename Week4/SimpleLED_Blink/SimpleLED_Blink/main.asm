;
; SimpleLED_Blink.asm
;
; Created: 30/10/2022 12:20:08 AM
; Author : Aizat
;

ldi r20, 0b00000011			
ldi r21, 0b00000000
ldi r22, 0b00000001
ldi r23, 0b00000010

out DDRB, R20				;sets the data direction for portB, pins 0,1 as output

loop:
	out PORTB, r22			;sends output to portB corresponding to the bit location
	call delay				;calls delay
	out PORTB, r23
	call delay
	out PORTB, r21
	call delay
	rjmp loop				;returns to the loop


;16 Million Cycles
;Ideally better to use timer modules, however for this basic example will use nested-loops to delay it
delay:
	ldi r16, 0xFE		;1 cycle
	ldi r17, 0xD3		;1 cycle
	ldi r18, 0x30		;1 cycle
	;0x30D3FE = 3199998
dloop:
	subi r16, 1		;1 cycle; subtracts the value of r16 by 1.
	sbci r17, 0		;1 cycle; subtracts the value of r17 by 0 and the carry over with subi if c-flag is risen.
	sbci r18, 0		;1 cycle
	brne dloop		;1 cycle if false- continue, 2 cycles true - jumps to loop 
	nop				;1 cycle each
	nop				;NOP servers no purpose but to add to the cycle amount
	nop
	nop
	ret				;4 Cycles
	

	;1 Second = 1e+6 microseconds, Atmega328p clocked at 16 MHz or 16e+6 clock cycles per seconds or 0.0625 microseconds per clock cycle 
	;Therefore 1e+6(microseconds)/0.0625(microseconds per clock cycle) = 16,000,000 Cycles
	;3(1) + 5(3199998) - 1 + 4(1) + 4 = 16,000,000 Cycles 