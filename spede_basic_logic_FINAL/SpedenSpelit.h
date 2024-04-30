#ifndef SPEDENSPELIT_H
#define SPEDENSPELIT_H
#include <arduino.h>

enum GameMode {
  MENU,
  GAME,
  STARTED,
  GAMEOVER
};

// funktioiden prototyypit, funktiot .ino:ssa
void startTheGame();
void gameOver();
void gameMenu();

void initializeGame();

//void initializeTimer();
//void checkGame(int);

void readHighscore();
void writeHighscore();
void resetHighScore();

#endif