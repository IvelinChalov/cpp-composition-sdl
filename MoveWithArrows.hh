#ifndef MOVE_WITH_ARROWS_BEHAVIOR_H
#define MOVE_WITH_ARROWS_BEHAVIOR_H

#include <SDL.h>
#include "MoveBehavior.hh"

class MoveWithArrows: public MoveBehavior{
  int wWidth, wHeight;

public:
    
  MoveWithArrows(int width, int height);
  
  int getX();

  int getY();

  void handleInput(SDL_Event& e);

  void move( SDL_Rect& wall );

  bool checkCollision( SDL_Rect a, SDL_Rect b );
};


#endif