#ifndef BUZZER_H
#define BUZZER_H
#include <arduino.h>

#define BUZZER 13 //D13 pinni

extern int nuottimaara; //melodian nuottimäärä
extern int NUOTIT[]; //nuottien taajuus

extern int nuottimaara2; //melodian nuottimäärä
extern int NUOTIT2[];  //nuottien taajuus

extern int nuotitLed;
extern int NUOTITLED[];


void PlaySound(void); //funktion proto
void PlaySound2(void); //funktion proto

#endif