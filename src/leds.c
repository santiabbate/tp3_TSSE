#include "leds.h"

#define ALL_OFF 0
#define BIT_ON 1
#define LED_OFFSET 1


static uint16_t * leds;

uint16_t Leds_Bits(uint8_t led)
{
    return (BIT_ON << (led - LED_OFFSET));
}


void Leds_Create(uint16_t * direccion)
{
    leds = direccion;
    *leds = 0;
}

void Leds_On(uint8_t led)
{
    *leds |= Leds_Bits(led);
}

void Leds_Off(uint8_t led)
{
    *leds &= ~(Leds_Bits(led));
}

void Leds_AllOn()
{
    *leds = 0xFFFF;
}

void Leds_AllOff()
{
    *leds = 0;
}

uint8_t Leds_Query(uint8_t led)
{
    uint8_t shiftAmount = led - LED_OFFSET;

    uint16_t ledMasked = *leds & (BIT_ON << shiftAmount);
    
    return ((ledMasked) >> shiftAmount);   
}