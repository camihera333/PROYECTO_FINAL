#include "tele.h"

//declaración de variables
int mensaje,i;
uint8_t gbits[5];
uint8_t cod[5];

//Declaración de pines y velocidad en baudios
void setup() {
pinMode(3,OUTPUT);
Serial.begin(9600);
digitalWrite(3,1);
   
}

void loop() {
  
  mensaje=analogRead(3); //lee el mensaje de 10 bits del pin 3 analogico
  Serial.println(mensaje);  //imprime el valor del mensaje leido
  transmision(mensaje,gbits); //Separa el mensaje en grupos de dos bits

  // ciclo para guardar los grupos de bits codificados en un arreglo
  for(i=0;i<5;i++)
      {
      cod[i]=codificacion(gbits[i]);
      //Serial.println(cod[i]);
      }

  
  datosruidoinicio(); // transmite los bits de ruido y de inicio

  // manda bits de inicio y final de transmmisión, asi como los paquetes de bits
  digitalWrite(3,0);
  delay(50);
  envio(cod[0]);
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
  envio(cod[1]);
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
  envio(cod[2]);
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
  envio(cod[3]);
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
  envio(cod[4]);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(100);
  digitalWrite(3,0);
  delay(50);
  digitalWrite(3,1);
  delay(1000);
  
  
}
