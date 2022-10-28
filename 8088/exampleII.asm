name "TP 7"
         
org 100h 
 ;al = primero
 ;ah = segundo
 ;bl = temporal
 ;bh = contador 0-FF
 ;cx = contador de big O notacion de bubble 3E8h 
 xor dx, dx ;TEMPORAL
 xor cx, cx ;CONTADOR         
 xor ax, ax ;PRIMERO
 xor bx, bx ;SEGUNDO           
 
 mov si, 0100h ;Posicion      
 mov bh, 0FFh ;Contador ff-0
 
 ;bh es un registro que se incrementa si no esta ordenado
 ;decrementa si lo esta
 ;cosa que se pueda detectar cuando no se incrementa mas
 ;es decir, esta todo ordenado.
 
 mov cx, 3E8h ;notacion Big O de bubble sort 

 
 recorrer: mov al,[si]
    inc si
    mov ah,[si]
    
    cmp al,ah 
    dec cx 
    JS ordenados ;
    
    ;Swap 
    inc bh
    mov bl, ah 
    mov al, bl 
    
    ;Hago efectivo el cambio
    mov [si],al   
    dec si
    
    mov [si],ah
    inc si
    
    jz terminoOrden
    ordenados:inc si
        dec bh
        jz terminoOrden
        loop recorrer

    cmp al,ah
 terminoOrden: hlt
 
 xor ax, ax
 xor dl, dl
 mov ah, 05h
 mov al, 0FFh
 
 loopthrough: mov al, [si]
  inc si
  dec al
  jz endLoop
  int 21h
  loop loopthrough

endLoop: hlt

 ret                      