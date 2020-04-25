#ifndef RACKET_HPP
#define RACKET_HPP

#include "constants.h"

class Racket {
    public:
        Racket(side_e side);
        Racket() = default;
        int collide(int y) const;
        int getX() const;
        int getY() const;
        void setY(int y);

    private:
        int _x;
        int _y;
        side_e _side;
};
#endif // RACKET_HPP
