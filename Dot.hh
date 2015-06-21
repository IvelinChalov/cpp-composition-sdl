#ifndef DOT_H
#define DOT_H

#include <SDL.h>
#include "MoveBehavior.hh"
#include "LTexture.hh"

class Dot{

protected:

  //Scene textures
  LTexture gDotTexture;
  MoveBehavior *moveBehavior;

  //The window renderer
  SDL_Renderer* gRenderer = NULL;

  SDL_Window* gWindow = NULL;

  //Set the wall
  SDL_Rect wall;

public:

  // Dot();
  ~Dot();

  //Shows the dot on the screen
  void render();


  void handleInput(SDL_Event& e){
    moveBehavior->handleInput(e);
  }

  void move(SDL_Rect& wall){
    moveBehavior->move(wall);
  }

  void update();
  void initRenderer();
  void setWindow(SDL_Window* window);
  void setWall(SDL_Rect w);

  bool loadMedia();


};

#endif