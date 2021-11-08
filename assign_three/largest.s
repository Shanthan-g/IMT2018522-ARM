    AREA    appcode, CODE, READONLY
    EXPORT __main
    IMPORT printMsg
    ENTRY

__main FUNCTION
    	MOV R1, #0x20000000 
	MOV R2, #00	
	MOV R3, #00	
	MOV R4, #04
	
    	MOV R5,#0XA	;VALUES
	MOV R6,#0XB
	MOV R7,#0XC
	
	CMP R5,R6	; if R5>R6 check with R7 and conclude	
	BGT GO
	B GO2		; if R6>R5 check with R7 and conclude
    	ADD R3, #01
	
GO	CMP R5,R7
	BLE OVER
	MOV R0, R5
	BL printMsg
	B STOP
		
GO2 	CMP R6,R7
	BLE OVER
	MOV R0,R6
	BL printMsg
	B STOP
	
OVER 	MOV R0,R7
	BL printMsg

STOP B STOP
    ENDFUNC
    END