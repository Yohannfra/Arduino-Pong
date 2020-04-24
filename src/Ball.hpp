#ifndef BALL_H
#define BALL_H

#include "constants.h"
#include "Racket.hpp"

class Ball {
    private:
        int _x;
        int _y;
        int _vx;
        int _vy;

    public:
        Ball();
        int update();
        void reset();
        side_e getSide() const;
        int getX() const;
        int getY() const;
};

#endif
