#ifndef YELLOW_DOT_H
#define YELLOW_DOT_H

#include "Dot.hh"
#include "MoveWithArrows.hh"

class YellowDot: public Dot{
  public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 10;

    //Initializes the variabl

    //Moves the dot and checks collision
    void move( SDL_Rect& wall );

    YellowDot(int, int);

  private:
    // //The X and Y offsets of the dot
    // int mPosX, mPosY;

    // //The velocity of the dot
    // int mVelX, mVelY;
    
    //Dot's collision box
    SDL_Rect mCollider;
};

#endif