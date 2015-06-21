#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include "YellowDot.hh"

#include <string>
#include <iostream>
using namespace std;

class Game{
public:

  //Screen dimension constants
  const static int SCREEN_WIDTH = 640;
  const static int SCREEN_HEIGHT = 480;

  //The window we'll be rendering to
  SDL_Window* gWindow = NULL;



  //Starts up SDL and creates window
  bool init();


  //Frees media and shuts down SDL
  void close();

  //Box collision detector
  bool checkCollision( SDL_Rect a, SDL_Rect b );

  void start();

};



#endif