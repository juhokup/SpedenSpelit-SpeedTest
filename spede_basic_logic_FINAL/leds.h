#ifndef LEDS_H
#define LEDS_H
#include "arduino.h"

extern int ledCount;

void initializeLeds();

void setLed(byte ledNumber);

void clearAllLeds(void);
void setAllLeds(void);

// ----- custom: (valoyhdistelmiä eri pelitiloihin)
void game_Started_LED(void);
void game_Ended_LED(void);
void newHighScore_LED(void);
void menuLEDS(void);

#endif