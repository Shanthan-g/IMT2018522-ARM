    AREA    appcode, CODE, READONLY
    EXPORT __main
    IMPORT printMsg
    ENTRY

__main FUNCTION
	MOV R0,#0	;first fib no.
	BL printMsg	

	MOV R0,#1	;second fib no.
	BL printMsg
	
	MOV R7,#10	;printing 10 more nums.
	
	MOV R5,#0
	MOV R6,#1
	
FOR	CMP R7,#00	;stop when printing is done
	BEQ STOP
	ADD R4,R5,R6
	MOV R0,R4	
	BL printMsg
	MOV R5,R6	;update R5 with the next value
	MOV R6,R4	;update R6 with the current result
	SUB R7,#01	
	B FOR
	
STOP B STOP
    ENDFUNC
    END