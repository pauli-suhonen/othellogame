#include<iostream>
#include <SDL.h>
#include "res_path.h"
#include "cleanup.h"
#include <string>
#include <SDL_image.h>
#include <vector>

const int SCREEN_WIDTH  = 480;
const int SCREEN_HEIGHT = 480;
const int TILE_SIZE = 60;

enum player{ empty,plr_black,plr_white};



/**
 * Log an SDL error with some error message to the output stream of our choice
 * @param os The output stream to write the message to
 * @param msg The error message to write, format will be msg error: SDL_GetError()
 */
void logSDLError(std::ostream &os, const std::string &msg){
  os << msg << " error: " << SDL_GetError() << std::endl;
}


SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
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
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
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
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
  int w, h;
  SDL_QueryTexture(tex, NULL, NULL, &w, &h);
  renderTexture(tex, ren, x, y, w, h);
}

bool SquareOccupiedByOpponent(player plr,int sqr_i,int sqr_j,std::vector<std::vector<player>> &board)
{
  if(board[sqr_i][sqr_j]!=plr && board[sqr_i][sqr_j]!=empty){
    return true;
  }else {
    return false;
  }
}

bool SquareOccupiedByPlayer(player plr,int sqr_i,int sqr_j,std::vector<std::vector<player>> &board)
{
  if(board[sqr_i][sqr_j]==plr){
    return true;
  }else {
    return false;
  }
}


bool Place_button(player plr,int sqr_i,int sqr_j, std::vector<std::vector<player>> &board)
{
  bool success=true;
  //topwards
  if(sqr_i>0&&SquareOccupiedByOpponent(plr,sqr_i-1,sqr_j,board)){
    bool dirSuccess=false;
    int firstOwn_i;
    for(int i=sqr_i-2;i>=0;i--){
      if(SquareOccupiedByPlayer(plr,i,sqr_j,board)){
	dirSuccess=true;
	success=true;
	firstOwn_i=i;
      }
    }
    if (dirSuccess){
      for(int i=sqr_i-2;i>firstOwn_i;i--){
	board[i][sqr_j]=plr;
      }
    }
  }
  if(success){
    board[sqr_i][sqr_j]=plr;
  }
  return success;
}



int main()
{

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    logSDLError(std::cout, "SDL_Init");
    return 1;
  }
  SDL_Window *window = SDL_CreateWindow("othello", 100, 100, SCREEN_WIDTH,
					SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr){
    logSDLError(std::cout, "CreateWindow");
    SDL_Quit();
    return 1;
  }
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
					      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr){
    logSDLError(std::cout, "CreateRenderer");
    cleanup(window);
    SDL_Quit();
    return 1;
  }
  const std::string resPath = getResourcePath("othello");
  SDL_Texture *blackbutton = loadTexture(resPath + "blackbutton.png", renderer);
  SDL_Texture *whitebutton = loadTexture(resPath + "whitebutton.png", renderer);
  SDL_Texture *emptysquare = loadTexture(resPath + "emptysquare.png", renderer);
  //Make sure they both loaded ok
  if ( blackbutton == nullptr || whitebutton == nullptr ||emptysquare == nullptr){
    cleanup(blackbutton,whitebutton,emptysquare, renderer, window);
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  SDL_Event e;
  bool quit=false;


  
  std::vector<std::vector<player>> board(8,std::vector<player>(8,empty));
  board[3][3]=plr_white;
  board[3][4]=plr_black;
  board[4][4]=plr_white;
  board[4][3]=plr_black;
  player playerInTurn=plr_black;
  while (!quit){
    int click_i,click_j;
    bool click=false;
    while (SDL_PollEvent(&e)){
      //If user closes the window
      if (e.type == SDL_QUIT){
	quit = true;
      }
      //If user presses any key
      if (e.type == SDL_KEYDOWN){
	quit = true;
      }
      //If user clicks the mouse
      if (e.type == SDL_MOUSEBUTTONDOWN){
	int mouseX,mouseY;
	SDL_GetMouseState(&mouseX,&mouseY);
	click_i=mouseX/60;
	click_j=mouseY/60;
	click=true;
      }


      if (click){
	if (playerInTurn==plr_white){
	  std::cout<<"white";
	  std::cout<<click_i<<click_j<<"\n";
	  Place_button(playerInTurn,click_i,click_j, board);
	  playerInTurn=plr_black;
	}else if (playerInTurn==plr_black){
	  std::cout<<"black";
	  std::cout<<click_i<<click_j<<"\n";
	  Place_button(playerInTurn,click_i,click_j, board);
	  playerInTurn=plr_white;
	}
      }

      //Rendering
      SDL_RenderClear(renderer);
      //Draw the image
      for (int i=0;i<8;i++){
	for (int j=0;j<8;j++){
	  renderTexture(emptysquare, renderer, i*TILE_SIZE, j*TILE_SIZE);
	  switch(board[i][j])
	    {
	    case empty:
	      break;
	    case plr_white:
	      renderTexture(whitebutton, renderer, i*TILE_SIZE, j*TILE_SIZE);
	      break;
	    case plr_black:
	      renderTexture(blackbutton, renderer, i*TILE_SIZE, j*TILE_SIZE);
	      break;
	    }
	  
	}
      }
      //Update the screen
      SDL_RenderPresent(renderer);


      
    }
  }
  cleanup( blackbutton,whitebutton,emptysquare, renderer, window);
  IMG_Quit();
  SDL_Quit();
  
  std::cout<<"Hello world!\n";
}


