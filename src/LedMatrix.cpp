#include "LedMatrix.hpp"
#include <Arduino.h>

void LedMatrix::Write_byte(unsigned char data)
{
    unsigned char i;

    digitalWrite(_pin_cs, LOW);
    for (i = 8; i >= 1; i--) {
        digitalWrite(_pin_clk, LOW);
        digitalWrite(_pin_din, data & 0x80);
        data = data << 1;
        digitalWrite(_pin_clk, HIGH);
    }
}

void LedMatrix::Write(unsigned char address, unsigned char dat)
{
    digitalWrite(_pin_cs, LOW);
    Write_byte(address);
    Write_byte(dat);
    digitalWrite(_pin_cs, HIGH);
}

LedMatrix::LedMatrix(int pin_clk, int pin_cs, int pin_din) :
_pin_clk(pin_clk), _pin_cs(pin_cs), _pin_din(pin_din)
{
    pinMode(_pin_clk, OUTPUT);
    pinMode(_pin_cs, OUTPUT);
    pinMode(_pin_din, OUTPUT);

    Write(0x09, 0x00); //decoding ：BCD
    Write(0x0a, 0x01); //brightness (de 0x01 a 0x0f)
    Write(0x0b, 0x07); //scanlimit；8 LEDs
    Write(0x0c, 0x01); //power-down mode：0，normal mode：1
    Write(0x0f, 0x00); //test display：1；EOT，display：0
    setAllMatrix(LOW);
}

void LedMatrix::setAllMatrix(int value)
{
    for (int i = 1; i <= 8; i++)
        Write(i, 0xFF * value);
}

void LedMatrix::displayRacket(side_e side, int y)
{
    int racket = 0b00000111;

    if (side == LEFT)
        Write(1, racket << y);
    else if (side == RIGHT)
        Write(8, racket << y);
}

void LedMatrix::displayBall(int x, int y)
{
    int pos = 0b00000001;

    Write(x, pos << y);
}
