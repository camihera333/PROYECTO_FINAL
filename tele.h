#include "arduino.h"
#include <stdint.h>

void transmision(int mensaje, uint8_t* gbits);
uint8_t codificacion(uint8_t gbit);
void envio(uint8_t codi);
void datosruidoinicio (void);
