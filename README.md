# Arduino Pong

A pong game made with an arduino uno, 2 8x8 led matrix and 2 potentiometers

## Pinout

Like described in src/constants.h

```c
// Pins matrix left
#define PIN_CLK_LEFT (8)
#define PIN_CS_LEFT (9)
#define PIN_DIN_LEFT (10)

// Pins matrix right
#define PIN_CLK_RIGHT (5)
#define PIN_CS_RIGHT (6)
#define PIN_DIN_RIGHT (7)

// Potentiometer left
#define POTENTIOMETER_PIN_LEFT (A1)

// Potentiometer right
#define POTENTIOMETER_PIN_RIGHT (A2)
```

## Build

- Install [PlatformIO](https://platformio.org/)

```
$ make
```

## Flash

```
$ make flash
```

## What it looks like

![Alt text](.github/pong_off.jpg)
![Alt text](.github/pong_on.jpg)

## Licence
This project is licensed under the terms of the MIT license.
