    AREA    appcode, CODE, READONLY
    EXPORT __main
    IMPORT printMsg
    ENTRY

__main FUNCTION
    	MOV R1, #0x20000000 ; base address
	MOV R2, #00	
	MOV R3, #00	
	MOV R4, #04	
	
    	MOV R5,#0XA	;value 1
	STR R5,[R1] 	
	
    	MOV R5, #0XB	;value 2 
    	STR R5, [R1, R4, LSL #0]

    	MOV R5, #0XC	;value 3
    	STR R5, [R1, R4, LSL #1]
	
	MOV R5, #0XD	;value 4
    	STR R5, [R1, #12]
	
	MOV R5, #0XE	;value 5
    	STR R5, [R1, R4, LSL #2]
	
	MOV R5, #0XF	;value 6
	STR R5, [R1, #20]
	

FOR	LDR R8,[R1]	;Loading current value into R8
	TST R8,#1	; AND with the LSB and conclude
	BNE SKIP
    	ADD R3, #01
SKIP
	ADD R2,#01
	CMP R2,#06
	BEQ OVER
	ADD R1,#04
	B FOR

OVER MOV R0,R3
	 BL printMsg

STOP B STOP
    ENDFUNC
    END