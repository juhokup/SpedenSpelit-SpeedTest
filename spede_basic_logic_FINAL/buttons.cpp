#include "buttons.h"
#include "display.h"

void initButtonsAndButtonInterrupts(void)
{
  pinMode(RST_BTN, INPUT_PULLUP);
  
  pinMode(BTN_0, INPUT_PULLUP);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);

  attachPCINT(digitalPinToPCINT(RST_BTN), i_RST_BTN, FALLING);  // use PCINT because it supports more pins
  
  attachPCINT(digitalPinToPCINT(BTN_0), i_BTN_0, FALLING);
  attachPCINT(digitalPinToPCINT(BTN_1), i_BTN_1, FALLING);
  attachPCINT(digitalPinToPCINT(BTN_2), i_BTN_2, FALLING);
  attachPCINT(digitalPinToPCINT(BTN_3), i_BTN_3, FALLING);
}

// ---------- custom:
void i_RST_BTN(void)
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > 800) // Suurempi aika erityyppisen napin vuoksi. If interrupts come faster than DEBOUNCE, assume it's a bounce and ignore
  {
    //Serial.println("\n*** RESETTED ***\n"); // keskeytyksessä tehtävät asiat
    state = GAME;
    ZeroDisplay(0); // asetetaan näytölle 0

    current_Time = millis(); // käynnistetään ajanotto peliä varten
  }
  last_interrupt_time = interrupt_time;
}

void i_BTN_0(void) // press in MENU will reset highscore
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE) // If interrupts come faster than DEBOUNCE, assume it's a bounce and ignore
  {
	if(state == MENU) resetHighScore();
  else {
      //Serial.println("BTN_0");
      if(ledArray[btn_x] == 16) {
        btn_x++;
        score++;
        displayNumber(score);
       
        //noTone(BUZZER);
        analogWrite(16, 0);
      }
      else state = GAMEOVER;
    }
  }
  last_interrupt_time = interrupt_time;
}
void i_BTN_1(void)
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > 250) // vihreä nappi hieman hitaampi
  {
  if(state == STARTED) {
    //Serial.println("BTN_1");
    if(ledArray[btn_x] == 17) {
      btn_x++;
      score++;
      displayNumber(score);
      
      //pressed = 1;
      //noTone(BUZZER);
      analogWrite(17, 0);
    }
    else state = GAMEOVER;
    }
  }
  last_interrupt_time = interrupt_time;
}
void i_BTN_2(void)
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE)
  {
  if(state == STARTED) {
    //Serial.println("BTN_2");
    if(ledArray[btn_x] == 18) {
      btn_x++;
      score++;
      displayNumber(score);
      
      //pressed = 1;
      //noTone(BUZZER);
      analogWrite(18, 0);
    }
    else state = GAMEOVER;
    }
  }
  last_interrupt_time = interrupt_time;
}
void i_BTN_3(void)
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE)
  {
  if(state == STARTED) {
    //Serial.println("BTN_3");
    if(ledArray[btn_x] == 19) {
      btn_x++;
      score++;
      displayNumber(score);
      //pressed = 1;
      //noTone(BUZZER);
      analogWrite(19, 0);
    }
    else state = GAMEOVER;
    }
  }
  last_interrupt_time = interrupt_time;
}