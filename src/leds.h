#include <stdint.h>

void Leds_Create(uint16_t * direccion);

void Leds_On(uint8_t led);

void Leds_Off(uint8_t led);

void Leds_AllOn();

void Leds_AllOff();

uint8_t Leds_Query(uint8_t led);