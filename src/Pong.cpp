#include "Pong.hpp"
#include "constants.h"

Pong::Pong() :
_score{0, 0},
_ledmatrix {
    LedMatrix(PIN_CLK_LEFT, PIN_CS_LEFT, PIN_DIN_LEFT),
    LedMatrix(PIN_CLK_RIGHT, PIN_CS_RIGHT, PIN_DIN_RIGHT)},
_rackets {
    Racket(LEFT),
    Racket(RIGHT)}
{

}

void Pong::resetVars()
{
    _ledmatrix[LEFT].setAllMatrix(LOW);
    _ledmatrix[RIGHT].setAllMatrix(LOW);
    _ball.reset();
}

void Pong::annimateGoal()
{
    for (int i = 0; i < 2; i++) {
        _ledmatrix[LEFT].setAllMatrix(HIGH);
        _ledmatrix[RIGHT].setAllMatrix(HIGH);
        delay(300);
        _ledmatrix[LEFT].setAllMatrix(LOW);
        _ledmatrix[RIGHT].setAllMatrix(LOW);
        delay(300);
    }
}

void Pong::updateBallPosition()
{
    int ball_pos = _ball.update(_rackets[LEFT], _rackets[RIGHT]);

    if (ball_pos == 1) {
        annimateGoal();
        resetVars();
    }
}

void Pong::updateRacketsPosition()
{
    int potleft= analogRead(POTENTIOMETER_PIN_LEFT);
    potleft = map(potleft, 0, 1023, 0, 600) / 100;
    _rackets[LEFT].setY(potleft);

    int potright= analogRead(POTENTIOMETER_PIN_RIGHT);
    potright = map(potright, 0, 1023, 0, 600) / 100;
    _rackets[RIGHT].setY(potright);
}

void Pong::start()
{
    resetVars();
    while (1) {
        updateBallPosition();
        updateRacketsPosition();
        if (_ball.getSide() == LEFT)
            _ledmatrix[LEFT].displayBall(_ball.getX(), _ball.getY());
        else
            _ledmatrix[RIGHT].displayBall(_ball.getX() - MATRIX_SIZE, _ball.getY());
        _ledmatrix[LEFT].displayRacket(LEFT, _rackets[LEFT].getY());
        _ledmatrix[RIGHT].displayRacket(RIGHT, _rackets[RIGHT].getY());
        delay(250);
        _ledmatrix[LEFT].setAllMatrix(LOW);
        _ledmatrix[RIGHT].setAllMatrix(LOW);
    }
}
