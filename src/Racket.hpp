#ifndef RACKET_HPP
#define RACKET_HPP

#include "constants.h"

class Racket {
    public:
        Racket(side_e side);
        Racket() = default;
        int collide(int y) const; // 0 : no | 1 : up | 2 : middle | 3 : down
        int getX() const;
        int getY() const;
        void setY(int y);

    private:
        int _x;
        int _y;
        side_e _side;
};
#endif // RACKET_HPP
