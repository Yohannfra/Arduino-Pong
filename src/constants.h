#ifndef CONSTANTS_H
#define CONSTANTS_H

// Pins matrix 1
#define PIN_CLK_LEFT (8)
#define PIN_CS_LEFT (9)
#define PIN_DIN_LEFT (10)

// Pins matrix 2
#define PIN_CLK_RIGHT (5)
#define PIN_CS_RIGHT (6)
#define PIN_DIN_RIGHT (7)

// Potentiometer 1
#define POTENTIOMETER_PIN_LEFT (A1)

// Potentiometer 2
#define POTENTIOMETER_PIN_RIGHT (A2)

// Matrix constants
#define MATRIX_SIZE (8)

// ball
#define DEFAULT_BALL_X (3)
#define DEFAULT_BALL_Y (4)
#define DEFAULT_BALL_VX (1)
#define DEFAULT_BALL_VY (1)

typedef enum {
    LEFT,
    RIGHT
} side_e;

#endif // CONSTANTS_H
