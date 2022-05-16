#include <stdio.h> 
#include <pic1687.h>

int main(){

SYNC = 0;// transmicion  asincronica 
BRGH = 1;//alta velocidad de transmicion 
SPBRG =  129 ;
TXIE =0; //desabilitamos interrupciones de transmicion 
TX9 = 0 ; //  transmitimos en 8 bits 
TXREG = "A";//valor a transmitir  
GIE =0 ;//interrupciones globales apagadas
PEIE = 0; //interrupciones perifericas apagadas
while(1){
    

}


}