name "TP 7"
         
org 100h 
 ;apunto a la pagina 1
 ;inicializo un contador con la cantidad de posiciones
 ;inicializo una variable temporal
 ;inicializo otra temporal

 ;si la resta levanta la flag de signo es mayor el restador
 ;intercambio y l
 
 
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
    
    cmp al,ah ;PRIMERO - SEGUNDO
    dec cx ;saco 1 a la notacion big O  
                   
    JS ordenados ;si estan ordenados no me interesan
    
    ;No lo estan
    ;Swap entre registros
    
    inc bh ; esta desordenado desorden++
    mov bl, ah ;temp = SEGUNDO
    mov ah, al ;SEGUNDO = PRIMERO
    mov al, bl ;PRIMERO = SEGUNDO
    
    ;Hago efectivo el cambio
    mov [si],al   
    dec si
    
    mov [si],ah
    inc si
    
    ;Explicacion 2-1
    ;1<2
    ;Orden correcto 1-2
    
    jz terminoOrden
    ordenados:inc si
        dec bh ;desorden--
        jz terminoOrden
        loop recorrer

    cmp al,ah ;PRIMERO - SEGUNDO
 terminoOrden: hlt
 ret                      