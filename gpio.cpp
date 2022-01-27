#include "gpio.h"
#include <lgpio.h>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    m_handel = lgGpiochipOpen(0);

    int init_state = 0;

    for(int pin : LEDS)
    {
        lgGpioClaimOutput(m_handel, LFLAGS, pin, init_state);
    }
}
//Destruktor
Gpio::~Gpio()
{
    int state = 0;
    for(int pin : LEDS)
    {
        lgGpioWrite(m_handel, pin, state);
    }

    lgGpiochipClose(m_handel);


}

void Gpio::set(int pin,bool value)
{
    lgGpioWrite(m_handel, pin, value);
}

void Gpio::set(unsigned int pattern)
{

    int stelle = 0;

    bool wert;

    unsigned int check = 0b0001;

    for(auto pin : LEDS)
    {

        wert = check & pattern>>stelle;
        lgGpioWrite(m_handel, pin, wert);
        stelle++;
    }
}
