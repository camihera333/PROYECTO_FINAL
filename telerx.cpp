#include "telerx.h"

int unir(uint8_t* datas) //funcion que une los valores decodificados, para reconstruir el valor enviado originalmente
{
    int val=0;
    val=(datas[0])|(datas[1]<<2)|(datas[2]<<4)|(datas[3]<<6)|(datas[4]<<8);
    return val;  
}
    
uint8_t decodificacion (uint8_t mncod) //funcion que decodifica los datos y los guarda en un arreglo
{	
	uint8_t decod[14]={0,0,0,0,0,0,0,0,0,0,0,1,2,3};
	return decod[mncod]; 
}


uint8_t asigbits () //funcion que dependiendo del tiempo de duracion que retorna pulseIn, define el valor de cada bit leido 
{
  uint8_t mencod=0;
  unsigned long d=pulseIn(3,HIGH);
  unsigned long d2=pulseIn(3,HIGH);
  
  if((d<=101000)&&(d>=99000)){
    bitWrite(mencod,3,1); 
    bitWrite(mencod,2,1);
    bitWrite(mencod,1,0);
        if((d2<=101000)&&(d2>=99000)){
         bitWrite(mencod,0,0);
        }
        if((d2<=51000)&&(d2>=49000)){
         bitWrite(mencod,0,1);
        }
  }
  
  if((d<=51000)&&(d>=49000)){
    bitWrite(mencod,3,1); 
    bitWrite(mencod,2,0);
    bitWrite(mencod,1,1);
        if((d2<=101000)&&(d2>=99000)){
         bitWrite(mencod,0,1);
        }
        if((d2<=51000)&&(d2>=49000)){
         bitWrite(mencod,0,0);
        }
    }
    return mencod;
}





