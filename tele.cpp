#include "tele.h"

void transmision(int mensaje, uint8_t* gbits) //funcion que separa el mensaje en grupos de dos bits
{         
  gbits[0]=(3)&(mensaje);
  gbits[1]=(((3<<2)&(mensaje))>>2)&(3);
  gbits[2]=(((3<<4)&(mensaje))>>4)&(3); 
  gbits[3]=(((3<<6)&(mensaje))>>6)&(3);
  gbits[4]=(((3<<8)&(mensaje))>>8)&(3);
}
    
    
uint8_t codificacion (uint8_t gbit) //funcion que codifica los grupos de bits del mensaje
{	
	uint8_t mcod[4]={10,11,12,13};
	return mcod[gbit]; 
}

void envio(uint8_t codi) // funcion que permite enviar bit a bit los datos
{	  
	 int i;
	 uint8_t lec; 
	 for(i=3;i>=0;i--){
		 lec=bitRead(codi,i);
		 digitalWrite(3,lec);
		 delay(50);
		 }
}	

void datosruidoinicio (void) //funcion que envia bits de ruido e inicio
{
  
  digitalWrite(3,0);
  delay(50);
  envio(10);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);

  
  digitalWrite(3,0);
  delay(50);
  envio(11);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
  digitalWrite(3,0);
  delay(50);
  envio(13);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
  digitalWrite(3,0);
  delay(50);
  envio(12);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
  digitalWrite(3,0);
  delay(50);
  envio(12);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
  digitalWrite(3,0);
  delay(50);
  envio(11);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
  digitalWrite(3,0);
  delay(50);
  envio(10);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
  digitalWrite(3,0);
  delay(50);
  envio(13);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
  digitalWrite(3,0);
  delay(50);
  envio(13);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
  digitalWrite(3,0);
  delay(50);
  envio(12);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
}

    
