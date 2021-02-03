	ORG 0H 
	SJMP START	 
	ORG 20H
START:
	MOV P1,#0FFH  ;p1 portu giris
	MOV P2,#0     ;cikisi sifirladim basta
PRESS:
	MOV R6,#20D   ;20 kere dönsün timer
	JB P1.0,PRESS	
LOOP:
	ACALL DELAY  //
	JB P1.0,RELEASE
	DJNZ R6,LOOP
	CPL P2.0
	SJMP PRESS
DELAY: 
	MOV TMOD,#01H ;50.000 mslik gecikme
	MOV TH0,#03CH  
	MOV TL0,#0B0H 
	SETB TR0 
TAKE:
	JNB TF0,TAKE  ;tasmayi kontrol ediyorum
	CLR TR0 
	CLR TF0 
	RETI
RELEASE:
	MOV P2,#0  ;butonu birak
	SJMP PRESS
	END


