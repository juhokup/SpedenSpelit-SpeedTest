#ifndef BUTTONS_H
#define BUTTONS_H

#include "arduino.h"
#include "PinChangeInterrupt.h"
#include "SpedenSpelit.h"
#include "buzzer.h"
#include "leds.h"

#define DEBOUNCE 200 // kytkinvärähtelyjen vuoksi aika, jonka aikana toista painallusta ei huomioida (ms)

#define RST_BTN 6

#define BTN_0 2
#define BTN_1 3
#define BTN_2 4
#define BTN_3 5

extern int state; // state-muuttuja, joka on int ja ei ole tässä tiedostossa (muuttujan prototyyppi)
extern int score; // score-muuttuja, joka on int ja ei ole tässä tiedostossa (muuttujan prototyyppi)
extern byte ledNumber;
extern unsigned long current_Time;

extern int ledArray[];
extern int btn_x;


extern void initializeDisplay(void);

// funktion prototyypit:
// setup functions:
void initButtonsAndButtonInterrupts(void);

// interrupt functions:
void i_RST_BTN(void);

void i_BTN_0(void);
void i_BTN_1(void);
void i_BTN_2(void);
void i_BTN_3(void);

#endif