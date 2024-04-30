#include <EEPROM.h>

#include "buttons.h" // sisältää myös muita, mm. SpedenSpelit.h
#include "display.h"
#include "leds.h"

#define INTERVAL_DEF 1000 // (oikeasti 1 sec)
#define SPEED 10

// game vars:
int score = 0;
int highscore = 0;
int state = MENU;
byte ledNumber = 0;

// "muistipelimuuttujat"
int ledCount=0;
int ledArray[100];
int buttonArray[100];
int btn_x = 0;
int led_x = 0;

// time vars:
int sound_duration = 650; // äänen sointiaika alussa, nopeutuu intervalin kanssa
int interval; // alkuarvo  1 sec = 1 Hz

unsigned long mainTime = 0;
unsigned long previousMillis = 0;
unsigned long current_Time = 0;
unsigned long elapsed_Time = mainTime - current_Time;
// -----------

void setup() {
  //Serial.begin(9600);
  initButtonsAndButtonInterrupts();
  initializeDisplay();
}

void loop() {
  readHighscore();
  displayhighscore(highscore); // näytetään suurin pistemäärä toisella 7-segmenttinäytöllä
  
  // tarkastetaan jokaisella loopin kierroksella, mikä on tilamuuttujan arvo
  if(state == MENU)
    gameMenu();
  else if(state == GAME){
    initializeGame();
    state = STARTED;
    game_Started_LED(); // LED-valoyhdistelmä
  }
  else if(state == STARTED)
    runGame();
  else {
    gameOver();
    game_Ended_LED(); // LED-valoyhdistelmä
    state = MENU;
  }
}


// *** FUNKTIOT ***

void initializeGame(){
  score = 0;
  displayNumber(score);
  sound_duration = 650;

  randomSeed(analogRead(0)); // analog-pinni 0 jätetään kytkemättä mihinkään, jolloin satunnaiset häiriöt mahdollistavat random-funktion aloittamisen satunnaisesta kohdasta
  for(int led_x = 0; led_x <= 99 ; led_x++){
    ledNumber = random(16,20); // taulukko luodaan
    ledArray[led_x] = ledNumber;
  }

  interval = INTERVAL_DEF;
  btn_x = 0;
  led_x = 0;
}

void runGame()
{

  mainTime = millis();
  if (mainTime - previousMillis >= interval)
  {
    previousMillis = mainTime;

    setLed(ledArray[led_x]); // intervalin välein sytytetään LED
    
    nuotitLed = ledArray[led_x]-16;
    tone(BUZZER, NUOTITLED[nuotitLed], sound_duration);
    
    //Serial.print("debug LED: "); Serial.println(ledArray[led_x]);
    led_x++;
    
    if (ledCount >= SPEED && ledCount % SPEED == 0) // SPEED = 10
		{
		  interval *= 0.9; // oikeasti 0.9
      sound_duration *= 0.9;
		}
  }

}

void gameMenu() // oletustila: tietty LED-valoyhdistelmä
{
  clearAllLeds();
  menuLEDS();
}

void gameOver() // peli päättynyt
{
  if(score > highscore) { // tarkistetaan, onko uusi suurin pistemäärä saatu, ja kirjoitetaan se muistiin. Lisäksi ajetaan audiovisuaaliset efektit
    highscore = score;
    writeHighscore();
    
    PlaySound2();
    newHighScore_LED();
  }
  else PlaySound();

  state = MENU; // seuraavalla loopilla ollaan takaisin MENU-tilassa, jolloin sitä vastaavaa funktiota kutsutaan
  ledNumber = 0; // estetään pisteiden kasvu pelin ulkopuolella

  /* debug:
  Serial.println("GAME OVER");
  Serial.print("Score: "); Serial.println(score);
  delay(1000);
  */
}

void readHighscore() { // luetaan EEPROMista suurin pistemäärä
  highscore = (EEPROM.read(0) << 8) + EEPROM.read(1);
  if(highscore == 0xffff)
    highscore = 0;
}

void writeHighscore() { // kirjoitetaan EEPROMiin suurin pistemäärä
  EEPROM.write(0, highscore >> 8);
  EEPROM.write(1, highscore & 0xff);
}

void resetHighScore(){ // poistetaan tieto suurimmasta pistemäärästä = asetetaan sen arvo nollaksi
  highscore = 0;
  writeHighscore();
}