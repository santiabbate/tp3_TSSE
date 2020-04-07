#include <unity.h>
#include "leds.h"

/*
 > Después de la inicialización todos los LEDs deben quedar apagados.
 > Se puede prender un LED individual.
 > Se puede apagar un LED individual.
 > Se pueden prender y apagar múltiples LED’s.
 > Se pueden prender todos los LEDs de una vez.
 > Se pueden apagar todos los LEDs de una vez.
 > Se puede consultar el estado de un LED.
 > Revisar limites de los parametros.
 Revisar parámetros fuera de los limites.
*/

static uint16_t ledsVirtuales;

// Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void)
{
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

// Se puede prender un LED individual.
void test_IndividualLedOn(void)
{
    const uint8_t led = 3;
    Leds_Create(&ledsVirtuales);
    Leds_On(led);
    TEST_ASSERT_EQUAL(1 << (led - 1), ledsVirtuales);
}

// Se puede apagar un LED individual.
void test_IndividualLedOff(void)
{
    const uint8_t led = 3;
    Leds_Create(&ledsVirtuales);
    Leds_On(led);
    Leds_Off(led);
    TEST_ASSERT_EQUAL(0, ledsVirtuales);
}

// Se pueden prender y apagar múltiples LED’s.
void test_MultipleLedOnOff(void)
{
    const uint8_t led = 3;
    Leds_Create(&ledsVirtuales);
    Leds_On(led);
    Leds_On(5);
    Leds_Off(5);
    TEST_ASSERT_EQUAL(1 << (led - 1), ledsVirtuales);
}

// Se pueden prender todos los LEDs de una vez.
void test_AllLedsOn(void)
{
    Leds_Create(&ledsVirtuales);
    Leds_AllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez.
void test_AllLedsOff(void)
{
    Leds_Create(&ledsVirtuales);
    Leds_AllOn();
    Leds_AllOff();
    TEST_ASSERT_EQUAL(0, ledsVirtuales);
}

// Se puede consultar el estado de un LED.
void test_QueryLed(void)
{
    uint8_t query;
    const uint8_t led = 7;
    Leds_Create(&ledsVirtuales);
    Leds_On(led);
    query = Leds_Query(led);
    TEST_ASSERT_EQUAL(1, query);
}

 // Revisar limites de los parametros.
 // Pruebo leds de los extremos
 void test_MultipleLedOnExtremos(void)
{
    const uint8_t ledHigh = 16;
    const uint8_t ledLow = 1;
    Leds_Create(&ledsVirtuales);
    Leds_On(ledHigh);
    Leds_On(ledLow);
    TEST_ASSERT_EQUAL((1 << (ledLow - 1)) + (1 << (ledHigh - 1)), ledsVirtuales);
}

// Revisar parámetros fuera de los limites.
// Pruebo encedido de leds fuera del rango
 void test_OutOfRangeOn(void)
{
    const uint8_t ledOutOfRange1 = 17;
    const uint8_t ledOutOfRange2 = 0xFF;
    Leds_Create(&ledsVirtuales);
    Leds_On(ledOutOfRange1);
    Leds_On(ledOutOfRange2);
    TEST_ASSERT_EQUAL(0, ledsVirtuales); // No debería encenderse ningún Led
}

// Revisar parámetros fuera de los limites.
// Pruebo apagado de leds fuera del rango
 void test_OutOfRangeOff(void)
{
    const uint8_t ledOutOfRange1 = 17;
    const uint8_t ledOutOfRange2 = 0xFF;
    Leds_Create(&ledsVirtuales);
    Leds_AllOn();
    Leds_Off(ledOutOfRange1);
    Leds_Off(ledOutOfRange2);
    TEST_ASSERT_EQUAL(0xFFFF, ledsVirtuales); // No debería apagarse ningún Led
}