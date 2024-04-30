#include "buzzer.h"

int nuottimaara = 14; //melodian nuottimäärä
int NUOTIT[] = {330, 392, 370, 294, 330, 247, 330, 392, 370, 247, 330, 392, 494, 659}; //nuottien taajuus
//int NUOTIT2[] = {349, 392, 392, 440, 392, 349, 392, 523, 494, 440, 349, 294, 247, 262};
int nuottimaara2 = 22; //melodian nuottimäärä
int NUOTIT2[] = {370, 277, 370, 370, 415, 440, 370, 370, 440, 415, 330, 330, 415, 440,370, 370, 370, 277, 370, 370, 415, 440};  //nuottien taajuus

int nuotitLed;
int NUOTITLED[] = {440, 554, 659, 831};  //nuottien taajuus


void PlaySound(void)
{
  for (int i = 0; i < nuottimaara; i++)  //soittaa arrayhyn tallenetut taajuudet läpi, soittaa jokaista taajuutta 200ms, lopettaa kun array päättyy
  {
    tone(BUZZER, NUOTIT[i]);
    delay(200);
  }
  noTone(BUZZER);
}

void PlaySound2()
{
  for (int i = 0; i < nuottimaara2; i++)  //soittaa arrayhyn tallenetut taajuudet läpi, soittaa jokaista taajuutta 200ms, lopettaa kun array päättyy
  {
    tone(BUZZER, NUOTIT2[i]);
    delay(200);
  }
  noTone(BUZZER);
}

