#include "Ball.hpp"

Ball::Ball()
{
    reset();
}

int Ball::update()
{
    int last_x = _x;
    int last_y = _y;

    _x += _vx;
    _y += _vy;

    if (_x < 1 || _x > 16) {
        _x = last_x; // TODO WIN/LOSE CONDITION (Or racket)
        _vx = -_vx;
        _x += (_x == 16) ? -1 : 1;
    }
    if (_y < 0 || _y > 7) {
        _y = last_y;
        _vy = -_vy;
        _y += (_y == 7) ? -1 : 1;
    }
    return 0;
}

void Ball::reset()
{
    _x = DEFAULT_BALL_X;
    _y = DEFAULT_BALL_Y;
    _vx = DEFAULT_BALL_VX;
    _vy = DEFAULT_BALL_VY;
}

side_e Ball::getSide() const
{
    if (_x <= MATRIX_SIZE)
        return LEFT;
    return RIGHT;
}

int Ball::getX() const
{
    return _x;
}

int Ball::getY() const
{
    return _y;
}
