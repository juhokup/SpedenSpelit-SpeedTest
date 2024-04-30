#include "leds.h"
#include "buzzer.h"

void initializeLeds()
{
  // intializes ANALOG pins A2,A3,A4,A5  to be used as outputs. LEDs are connected to those pins.
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void setLed(byte ledNumber)
{
  clearAllLeds();
  //noTone(BUZZER);
  ledCount++;
  delay(100);
  analogWrite(ledNumber, 128);

  /*
  setLed(byte) sets correct led given as A2, A3, A4 or A5
  Arduino pin A2 = 16
  Arduino pin A3 = 17
  Arduino pin A4 = 18
  Arduino pin A5 = 19
  */
}

void clearAllLeds(void)
{
  // clearAllLeds(void) subroutine clears all leds
  analogWrite(A2, 0);
  analogWrite(A3, 0);
  analogWrite(A4, 0);
  analogWrite(A5, 0);
}

void setAllLeds(void)
{
  // setAllLeds subroutine sets all leds ON
  analogWrite(A2, 128);
  analogWrite(A3, 128);
  analogWrite(A4, 128);
  analogWrite(A5, 128);
}

// ----- custom:

void game_Started_LED(void)
{
  clearAllLeds();
  delay(500);
  setAllLeds();
    tone(BUZZER, NUOTIT2[0]);
    delay(200);
    noTone(BUZZER);
  clearAllLeds();
    tone(BUZZER, NUOTIT2[1]);
    delay(200);
    noTone(BUZZER);
  setAllLeds();
    tone(BUZZER, NUOTIT2[2]);
    delay(200);
    noTone(BUZZER);
  clearAllLeds();
    tone(BUZZER, NUOTIT2[3]);
    delay(200);
    noTone(BUZZER);
  delay(200);
}

void game_Ended_LED(void)
{
  clearAllLeds();
  delay(300);
  setAllLeds();
  delay(300);

  clearAllLeds();
  delay(300);
  setAllLeds();
  delay(700);
}

void newHighScore_LED(void)
{
  setLed(19);
  delay(150);
  setLed(18);
  delay(100);
  setLed(17);
  delay(100);
  setLed(16);
  delay(300);

  setLed(16);
  delay(100);
  setLed(17);
  delay(100);
  setLed(18);
  delay(100);
  setLed(19);
  delay(300);
  /*
  clearAllLeds();
  delay(300);
  setAllLeds();
  delay(300);
  clearAllLeds();
  delay(300);
  setAllLeds();
  delay(700);  
  */
}

void menuLEDS(void)
{
  analogWrite(17, 128);
  analogWrite(18, 128);
  delay(150);
  analogWrite(17, 0);
  analogWrite(18, 0);
  
  analogWrite(16, 128);
  analogWrite(19, 128);
  delay(130);
  analogWrite(17, 0);
  analogWrite(18, 0);
  delay(250);
  clearAllLeds();
  delay(600);
}