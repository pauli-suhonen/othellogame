#include "CBoardGUI.h"

CBoardGUI::CBoardGUI()
{
}

int CBoardGUI::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    logSDLError(std::cout, "SDL_Init");
    return 1;
  }
  window = SDL_CreateWindow("othello", 100, 100, SCREEN_WIDTH,
					SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr){
    logSDLError(std::cout, "CreateWindow");
    SDL_Quit();
    return 1;
  }
  renderer = SDL_CreateRenderer(window, -1,
					      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr){
    logSDLError(std::cout, "CreateRenderer");
    cleanup(window);
    SDL_Quit();
    return 1;
  }
  const std::string resPath = getResourcePath("othello");
  blackbutton = loadTexture(resPath + "blackbutton.png", renderer);
  whitebutton = loadTexture(resPath + "whitebutton.png", renderer);
  emptysquare = loadTexture(resPath + "emptysquare.png", renderer);
  //Make sure they both loaded ok
  if ( blackbutton == nullptr || whitebutton == nullptr ||emptysquare == nullptr){
    cleanup(blackbutton,whitebutton,emptysquare, renderer, window);
    IMG_Quit();
    SDL_Quit();
    return 1;
  }
  return 0;
}



/**
 * Log an SDL error with some error message to the output stream of our choice
 * @param os The output stream to write the message to
 * @param msg The error message to write, format will be msg error: SDL_GetError()
 */
void CBoardGUI::logSDLError(std::ostream &os, const std::string &msg){
  os << msg << " error: " << SDL_GetError() << std::endl;
}


SDL_Texture* CBoardGUI::loadTexture(const std::string &file, SDL_Renderer *ren){
  SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
  if (texture == nullptr){
    logSDLError(std::cout, "LoadTexture");
  }
  return texture;
}

/**
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
 * width and height
 * @param tex The source texture we want to draw
 * @param ren The renderer we want to draw to
 * @param x The x coordinate to draw to
 * @param y The y coordinate to draw to
 * @param w The width of the texture to draw
 * @param h The height of the texture to draw
 */
void CBoardGUI::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
  //Setup the destination rectangle to be at the position we want
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  dst.w = w;
  dst.h = h;
  SDL_RenderCopy(ren, tex, NULL, &dst);
}


/**
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
 * the texture's width and height
 * @param tex The source texture we want to draw
 * @param ren The renderer we want to draw to
 * @param x The x coordinate to draw to
 * @param y The y coordinate to draw to
 */
void CBoardGUI::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
  int w, h;
  SDL_QueryTexture(tex, NULL, NULL, &w, &h);
  renderTexture(tex, ren, x, y, w, h);
}



void CBoardGUI::Render(std::vector<std::vector<color>> board)
{
    //Rendering
    SDL_RenderClear(renderer);
    //Draw the image
    for (int i=0;i<8;i++){
      for (int j=0;j<8;j++){
	renderTexture(emptysquare, renderer, j*TILE_SIZE, i*TILE_SIZE);
	switch(board[i][j])
	  {
	  case empty:
	    break;
	  case plr_white:
	    renderTexture(whitebutton, renderer, j*TILE_SIZE, i*TILE_SIZE);
	    break;
	  case plr_black:
	    renderTexture(blackbutton, renderer, j*TILE_SIZE, i*TILE_SIZE);
	    break;
	  }
	  
      }
    }
    //Update the screen
    SDL_RenderPresent(renderer);
}

  
CBoardGUI::~CBoardGUI()
{
  cleanup( blackbutton,whitebutton,emptysquare, renderer, window);
}
