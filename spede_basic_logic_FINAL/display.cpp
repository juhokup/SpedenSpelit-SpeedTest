#include "display.h"

int data [] = {1, 79, 18, 6, 76, 36, 32, 15, 0, 4,};  // taulukkoon 0-9 arvot XOR käännettynä binääristä desimaaliin muutettuna.
int data2 [] = {1, 79, 18, 6, 76, 36, 32, 15, 0, 4,}; //samat arvot highscore näytölle

void initializeDisplay(void)
{

/*
#define DATA 7  //pinnien määrittelyt, määritelty muualla.
#define LATCH 8
#define CLOCK 9
#define DATA2 10
#define LATCH2 11
#define CLOCK2 12
*/


int score;   //score globaali muuttuja
int highscore;  //highscore globaali muuttuja

  pinMode(LATCH, OUTPUT);  //3x D-pinniä per 2x näyttöä, serial in data, kello, ja latch asetetaan outputeiksi
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH2, OUTPUT);
  pinMode(CLOCK2, OUTPUT);
  pinMode(DATA2, OUTPUT);
  
}

void displayNumber(int n) {   //score näytön funktio, näyttää numeroita 0-99 int muodossa funktiota kutsuttaessa
  int temp = score;  //väliaikainen muuttuja = score, tempillä saadaan jaettua hetkellisesti score muuttuja kahdelle näytöllä 
  int ones = temp % 10;  //yköset modulo
  temp = temp /10; // jaetaan se kymmenellä
  int tens = temp % 10; //kympit tästä vielä modulo
    digitalWrite(LATCH, LOW); //latch low kun kirjoitetaan
    shiftOut(DATA, CLOCK, LSBFIRST, data [ones]);  //kirjoitetaan data kahdelle näytölle, tallenetaan käytännössä kahteen arrayhyn
    shiftOut(DATA, CLOCK, LSBFIRST, data [tens]);
    digitalWrite(LATCH, HIGH); //latch high, kun lopetetaan kirjoitus
}
  


void displayhighscore(int n) {  //highscorelle samat setit kuin scorelle, muuttujien nimet ja D-pinnit erit, toimintaperiaate sama
	/*int highscore = EEPROM.read(0); //highscoren kirjoituksen prototyyppi, gamelogicissa käytössä oleva versio.
	if (score > highscore) {
		highscore = score;
		EEPROM.write(0, highscore);
  }*/
  int temp2 = highscore;
  int ones2 = temp2 % 10;
  temp2 = temp2 /10;
  int tens2 = temp2 % 10;
    digitalWrite(LATCH2, LOW);
    shiftOut(DATA2, CLOCK2, LSBFIRST, data2 [ones2]);
    shiftOut(DATA2, CLOCK2, LSBFIRST, data2 [tens2]);
    digitalWrite(LATCH2, HIGH);
  }
  
  void ZeroDisplay(int n) {  //näyttöjen nollaus prototyyppi, ei käytössä, saatiin toimimaan, kun displaynumber funktioon kirjoiteaan resettiä painaessa nolla.
	digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, data[0]);
    shiftOut(DATA, CLOCK, LSBFIRST, data[0]);
    digitalWrite(LATCH, HIGH);
}