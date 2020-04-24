#ifndef PONG_HPP
#define PONG_HPP

#include <Arduino.h>
#include "LedMatrix.hpp"
#include "Ball.hpp"
#include "Racket.hpp"

class Pong {
    private:
        unsigned long _clock;
        void updateBallPosition();
        void updateRacketsPosition();
        void annimateGoal();
        void resetVars();

        unsigned int _score[2];
        LedMatrix _ledmatrix[2];
        Racket _rackets[2];
        Ball _ball;


    public:
        Pong();
        void start();
};

#endif
