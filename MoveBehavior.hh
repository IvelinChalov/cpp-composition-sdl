#ifndef MOVE_BEHAVIOR_H
#define MOVE_BEHAVIOR_H

#include <SDL.h>

class MoveBehavior{
  protected:
  //The velocity of the dot
  int mVelX, mVelY;
  //The X and Y offsets of the dot
  int mPosX, mPosY;

  //Dot's collision box
  SDL_Rect mCollider;

  static const int DOT_VEL = 10;
  //The dimensions of the dot
  static const int DOT_WIDTH = 20;
  static const int DOT_HEIGHT = 20;

  public:
    virtual void handleInput(SDL_Event& e) = 0;
    virtual void move(SDL_Rect& wall) = 0;

    virtual int getX() = 0;
    virtual int getY() = 0;

};


#endif