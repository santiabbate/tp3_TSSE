#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"
static uint16_t ledsVirtuales;



void setUp(void)

{

    Leds_Create(&ledsVirtuales);

}



void tearDown(void)

{



}





void test_LedsOffAfterCreate(void)

{

    uint16_t ledsVirtuales = 0xFFFF;

    Leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IndividualLedOn(void)

{

    const uint8_t led = 3;

    Leds_Create(&ledsVirtuales);

    Leds_On(led);

    UnityAssertEqualNumber((UNITY_INT)((1 << (led - 1))), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_INT);

}





void test_IndividualLedOff(void)

{

    const uint8_t led = 3;

    Leds_Create(&ledsVirtuales);

    Leds_On(led);

    Leds_Off(led);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

}





void test_MultipleLedOnOff(void)

{

    const uint8_t led = 3;

    Leds_Create(&ledsVirtuales);

    Leds_On(led);

    Leds_On(5);

    Leds_Off(5);

    UnityAssertEqualNumber((UNITY_INT)((1 << (led - 1))), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}





void test_AllLedsOn(void)

{

    Leds_Create(&ledsVirtuales);

    Leds_AllOn();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX16);

}





void test_AllLedsOff(void)

{

    Leds_Create(&ledsVirtuales);

    Leds_AllOn();

    Leds_AllOff();

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}





void test_QueryLed(void)

{

    uint8_t query;

    const uint8_t led = 7;

    Leds_Create(&ledsVirtuales);

    Leds_On(led);

    query = Leds_Query(led);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((query)), (

   ((void *)0)

   ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

}







 void test_MultipleLedOnExtremos(void)

{

    const uint8_t ledHigh = 16;

    const uint8_t ledLow = 1;

    Leds_Create(&ledsVirtuales);

    Leds_On(ledHigh);

    Leds_On(ledLow);

    UnityAssertEqualNumber((UNITY_INT)(((1 << (ledLow - 1)) + (1 << (ledHigh - 1)))), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);

}







 void test_OutOfRangeOn(void)

{

    const uint8_t ledOutOfRange1 = 17;

    const uint8_t ledOutOfRange2 = 0xFF;

    Leds_Create(&ledsVirtuales);

    Leds_On(ledOutOfRange1);

    Leds_On(ledOutOfRange2);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_INT);

}







 void test_OutOfRangeOff(void)

{

    const uint8_t ledOutOfRange1 = 17;

    const uint8_t ledOutOfRange2 = 0xFF;

    Leds_Create(&ledsVirtuales);

    Leds_AllOn();

    Leds_Off(ledOutOfRange1);

    Leds_Off(ledOutOfRange2);

    UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_INT);

}
