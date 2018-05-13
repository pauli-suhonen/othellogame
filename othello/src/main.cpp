#include<iostream>
#include <string>
#include <vector>
#include "OthelloUtil.h"
#include "CInputParser.h"
#include "CBoardGUI.h"
#include "CPlayer.h"
#include "CComputerPlayer.h"
#include "CHumanPlayer.h"
#include "COthelloInstance.h"

int main()
{
  CBoardGUI boardGui;
  if (boardGui.Init())
    return 1;
  CHumanPlayer player1(&boardGui.input,plr_black);
  CComputerPlayer player2(plr_white);
  COthelloInstance gameInstance(&player1,&player2);

  while (!boardGui.input.QuitRequested() && !gameInstance.gameEnded){
    boardGui.input.ParseInput();
    if(gameInstance.PlayerInTurnGetMove()){
      if(gameInstance.PlayerInTurnUseMove()){
	gameInstance.DetermineNewPlayerInTurn();
      }
    }
    boardGui.Render(gameInstance.board);
  }
  IMG_Quit();
  SDL_Quit();
  std::cout<<"end\n";
}


