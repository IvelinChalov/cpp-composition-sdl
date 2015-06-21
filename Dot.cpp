#include "Dot.hh"

void Dot::setWall(SDL_Rect w){
  wall = w;
}

bool Dot::loadMedia(){
  //Loading success flag
  bool success = true;

  //Load press texture
  if( !gDotTexture.loadFromFile( "dot.bmp" ) ){
    printf( "Failed to load dot texture!\n" );
    success = false;
    throw -1;
  }

  return success;
}

void Dot::setWindow(SDL_Window* window){
  gWindow = window;
}

void Dot::initRenderer(){
  //Create vsynced renderer for window
  gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
  if( gRenderer == NULL ){
    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
    throw -1;
  }else{
    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ){
      printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
      throw -1;
    }
  }
  gDotTexture.setRenderer(gRenderer);
}

void Dot::update(){
  //Move the dot and check collision
  move( wall );

  //Clear screen
  SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear( gRenderer );

  //Render wall
  SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );    
  SDL_RenderDrawRect( gRenderer, &wall );
  
  //Render dot
  render();

  //Update screen
  SDL_RenderPresent( gRenderer );
}

// Dot::Dot(){
// }

Dot::~Dot(){
  //Free loaded images
  gDotTexture.free();
  SDL_DestroyRenderer( gRenderer );
  gRenderer = NULL;
}

void Dot::render(){
  int posX = moveBehavior->getX();
  int posY = moveBehavior->getY();
  gDotTexture.render( posX, posY );
}
