#include "funciones.h"

  void transmision(int mensaje)
    {
      int gbits,gbits2,gbits3,gbits4;
      
      gbits=(7)&(mensaje);
      gbits2=(((7<<3)&(mensaje))>>3);
      gbits3=(((7<<6)&(mensaje))>>6); 
      gbits4=(((7<<9)&(mensaje))>>9);
      
      
    }
    
    
   uint8_t codificacion (gbit)
   {
     uint8_t cod[]={0,41,26........};
     
     return cod[gbit];
     
   }
    
