#ifndef CBOARDGUI_H
#define CBOARDGUI_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <vector>
#include<iostream>
#include "res_path.h"
#include "cleanup.h"
#include "OthelloUtil.h"
#include "CInputParser.h"
#include "CPlayer.h"
#include "CComputerPlayer.h"
#include "CHumanPlayer.h"
#include "COthelloInstance.h"


class CBoardGUI{
 public:
  CInputParser input;
  Render(std::vector<std::vector<color>> board);
 private:
  const int SCREEN_WIDTH  = 480;
  const int SCREEN_HEIGHT = 480;
  const int TILE_SIZE = 60;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *blackbutton;
  SDL_Texture *whitebutton;
  SDL_Texture *emptysquare;
  void logSDLError(std::ostream &os, const std::string &msg);
  SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
  void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
  void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
}


#endif CBOARDGUI_H
