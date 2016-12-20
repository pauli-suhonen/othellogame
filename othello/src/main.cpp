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
enum direction{ north,northeasst,east,southeast,south,southwest,west,northwest};



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

player OppositePlayer(player plr)
{
  if (plr==plr_white){
    return plr_black;
  }
  if (plr==plr_black){
    return plr_white;
  }
}





void FindValidMoves(player plr,const std::vector<std::vector<player>> &board,std::vector<int> &validMoves,std::vector<std::vector<int>> &buttonsToFlip)
{
  validMoves.clear();
  buttonsToFlip.clear();
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if (board[i][j]!=empty){
	  continue;
      }
      std::vector<int> flipping;
      std::vector<int> flippingTemp;

      //north
      flippingTemp.clear();
      int ii=i-1;
      int jj=j;
      while (ii>0 && board[ii][jj]==OppositePlayer(plr)){
	flippingTemp.push_back(ii*8+jj);
	ii=ii-1;
      }
      if(ii>0 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }


      if(flipping.size()>0){
	validMoves.push_back(i*8+j);
	buttonsToFlip.push_back(flipping);
      }
    }
  }

  std::cout<<"validMoves.size():"<<validMoves.size()<<"\n";
  for(int k=0;k<validMoves.size();k++){
    std::cout<<"validMoves:"<<validMoves[k]<<"\ti"<<validMoves[k]/8<<"\tj"<<validMoves[k]%8<<"\n";
  }
}










void PlaceButton(player plr,int sqr_i,int sqr_j, std::vector<std::vector<player>> &board,int buttonsToFlipIndex, std::vector<std::vector<int>> buttonsToFlip)
{
  board[sqr_i][sqr_j]=plr;
  for(std::vector<int>::iterator it=buttonsToFlip[buttonsToFlipIndex].begin();it!=buttonsToFlip[buttonsToFlipIndex].end();it++){
    board[*it/8][*it%8]=plr;
  }
 
}


bool CheckForValidMove(int i,int j,int &index,std::vector<int> &validMoves){
  std::cout<<"validMoves.size():"<<validMoves.size()<<"\n";
  for(index=0;index<validMoves.size();index++){
    std::cout<<"index:"<<index<<"\n";
    if (validMoves[index]==(i*8+j)){
      std::cout<<"check_true\n";
      return true;
    }
  }
  std::cout<<"check_false\n";
  return false;
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
  
  std::vector<int> validMoves;
  std::vector<std::vector<int>> buttonsToFlip;
  FindValidMoves(playerInTurn,board,validMoves, buttonsToFlip);

  std::cout<<"before while validMoves.size()"<<validMoves.size()<<"\n";
  
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
	click_j=mouseX/60;
	click_i=mouseY/60;
	click=true;
      }


      
      
      if (click){
	int buttonsToFlipIndex;
	if (CheckForValidMove(click_i,click_j,buttonsToFlipIndex,validMoves)){
	    PlaceButton(playerInTurn,click_i,click_j, board,buttonsToFlipIndex,buttonsToFlip);
	    playerInTurn=OppositePlayer(playerInTurn);
	    FindValidMoves(playerInTurn,board,validMoves, buttonsToFlip);
	    if(validMoves.size()==0){
	      playerInTurn=OppositePlayer(playerInTurn);
	      FindValidMoves(playerInTurn,board,validMoves, buttonsToFlip);
	    }
	}	
      }

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
  }
  cleanup( blackbutton,whitebutton,emptysquare, renderer, window);
  IMG_Quit();
  SDL_Quit();
  
  std::cout<<"Hello world!\n";
}


