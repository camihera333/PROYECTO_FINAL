#include "telerx.h"

//Declaración de variables 
uint8_t mencod=0,dd[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},leer=0,cont=0,correc[5]={0,0,0,0,0};
int val=0,h=0;

//Declaración de pines y velocidad en baudios
void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  leer=digitalRead(3); // lee los bits del pin 3 digital
  while(leer) //ciclo que espera mientras esté leyendo un dato
  {leer=digitalRead(3);}
   mencod=asigbits(); //funcion que dependiendo del tiempo de duracion que retorna pulseIn, define el valor de cada bit leid
    dd[cont]=decodificacion(mencod); //funcion que decodifica los datos y los guarda en un arreglo
    Serial.println(mencod);
    cont++;
    if (cont==30)
    {
      cont=0;
      for(int j=0;j<30;j++)
      {
        h=dd[j]+dd[j+1]+dd[j+2]+dd[j+3]+dd[j+4];
        if(h==9)
        {
          if((dd[j]==1)&&(dd[j+1]==0)&&(dd[j+2]==3)&&(dd[j+3]==3)&&(dd[j+4]==2))
          {
             for(int i=0;i<5;i++)
             {
              correc[i]=dd[j+5+i];
             }
             break;
          }
        }
      }
      val=unir(correc); //funcion que une los valores decodificados, para reconstruir el valor enviado originalmente
      Serial.println(val);
      analogWrite(9,val);
    }
    delay (500);
    

}
