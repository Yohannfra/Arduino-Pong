#include "Racket.hpp"

#include "constants.h"

Racket::Racket(side_e side) : _side(side)
{
    _y = 2;
    _x = (_side == LEFT) ? 0 : 15;
}

int Racket::collide(int y) const
{
    return (_y == y) ? 1 : (_y + 1 == y) ? 2 : (_y + 2 == y) ? 3 : 0;
}

int Racket::getX() const
{
    return _x;
}

int Racket::getY() const
{
    return _y;
}

void Racket::setY(int y)
{
    if (y > 5)
        y = 5;
    _y = y;
}
