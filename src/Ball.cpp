#include "Ball.hpp"

Ball::Ball()
{
    reset();
}

int Ball::update(Racket &racketLeft, Racket &racketRight)
{
    int last_x = _x;
    int last_y = _y;

    _x += _vx;
    _y += _vy;

    if (_x == 0 || _x == 17)
        return 1;

    if (_x == 1 || _x == 16) {
        int collideLeft = racketLeft.collide(_y);
        int collideRight = racketRight.collide(_y);
        if (_x == 1 && collideLeft != 0) {
            _x = last_x;
            _vx = -_vx;
            _vy = (collideLeft == 1) ? -1 : (collideLeft == 3) ? 1 : 0;
        } else if (_x == 16 && collideRight != 0) {
            _x = last_x;
            _vx = -_vx;
            _vy = (collideRight == 1) ? -1 : (collideRight == 3) ? 1 : 0;
        }
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
