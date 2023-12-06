#include "../inc/Debug.h"
#include "../inc/Button.h"

/*###########################################################################################################################################*/
/*
 *
 *     CONSTRUCTORS
 *
 */
/*###########################################################################################################################################*/
Button::Button(const char* topic, uint8_t pin_number, void (*ISR_Button)() ) :
    Device(topic), _pinNumber(pin_number)
{
    pinMode(_pinNumber, INPUT);

    // we will use isr approach
    attachInterrupt(digitalPinToInterrupt(_pinNumber), ISR_Button, CHANGE);
}

/*###########################################################################################################################################*/
/*
 *
 *     PUBLIC methods
 *
 */
/*###########################################################################################################################################*/
void Button::Pressed()
{
    _buttonState = true;
}
void Button::Reset(){
    _buttonState = false;
}

#define JSON_BUFFER_SIZE 20
String Button::Get_Current_State(){
    char jsonBuffer[JSON_BUFFER_SIZE];
    snprintf(jsonBuffer, JSON_BUFFER_SIZE, "{\"button\":%c}", _buttonState ? '1' : '0');
    return String(jsonBuffer);
}


/*###########################################################################################################################################*/
/*
 *
 *     PRIVATE methods
 *
 */
/*###########################################################################################################################################*/

