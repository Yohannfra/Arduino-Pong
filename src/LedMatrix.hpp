#ifndef LED_MATRIX_H
#define LED_MATRIX_H

#include "constants.h"

class LedMatrix {
    private:
        int _pin_clk;
        int _pin_cs;
        int _pin_din;
        void Write(unsigned char address, unsigned char dat);
        void Write_byte(unsigned char DATA);

    public:
        LedMatrix(int pin_clk, int pin_cs, int pin_din);
        LedMatrix() = default;
        void setAllMatrix(int value);
        void displayRacket(side_e side, int y);
        void displayBall(int x, int y);
};

#endif
