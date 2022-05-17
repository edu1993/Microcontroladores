#include <stdio.h>
#include <pix1687x.h>


int main(){
int decimal;
TRISB=0b00000000;
TRISC=0b00000000;
TRISA=0b00000001;
int res=0; //variable guarda suma ADRESH + ADRESL
ADCS1=1;
ADCS0=0;//RELOJ CONVERSOR AD 

CHS2=0;
CHS1=0;
CHS0=0;//CANAL DE CONVERCION


ADFM=1;//AROJAMOS EL RESULTADO MENOS SIGNIFICATIVO A LA DERECHA

PCFG3=1;
PCFG2=1;
PCFG1=1;
PCFG0=0;//PONEMOS TODO A DIGITAL MENOS EL 0


ADIF=0;//Activar interrupcion moudlo A/D
ADIE=1;
GIE=1;
PEIE=1;


ADON=1;//ACTIVAMOS CONVERCION AD


while(1){
ADIF=0;//FLAG DE INTERUPCION AD
ADGO=1;//BIT DEL ESTADO DE LA CONVERCION 
while(!ADGO);

if(ADRESH == 0b00000001){
	res = ADRESL+256;

}

if(ADRESH == 0b00000010){
	res = ADRESL+512;

}

if(ADRESH == 0b00000011){
	res = ADRESL+768;

}

if(ADRESH == 0b00000000){
	res = ADRESL;

}

if(res>=40){
	PORTB = 0b00000011;//prendo ventilador y alarma 

}
 if(res<=20){
 	PORTB = 0b00000011;//apago ventilador y alarma 
 }

 }



