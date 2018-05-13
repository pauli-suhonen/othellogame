#include "CGameHumanVsHuman.h"
#include "OthelloUtil.h"
#include "CInputParser.h"
#include "CBoardGUI.h"
#include "CPlayer.h"
#include "CComputerPlayer.h"
#include "CHumanPlayer.h"
#include "COthelloInstance.h"
#include "SDL.h"

CGameHumanVsHuman::CGameHumanVsHuman():
  player1(CHumanPlayer(&boardGui.input,plr_black)),
  player2(CHumanPlayer(&boardGui.input,plr_white)),
  gameInstance(COthelloInstance(&player1,&player2))
  
{
  if (boardGui.Init())
    std::cout<<"Error in boardGui.Init()\n";
  boardGui.Render(gameInstance.board);
  while (!boardGui.input.QuitRequested() && !gameInstance.gameEnded){
    SDL_Delay(50);
    boardGui.input.ParseInput();
    if(gameInstance.PlayerInTurnGetMove()){
      if(gameInstance.PlayerInTurnUseMove()){
	gameInstance.DetermineNewPlayerInTurn();
      }
    }
    boardGui.Render(gameInstance.board);
  }
  while (!boardGui.input.QuitRequested()){
    boardGui.input.ParseInput();
  }
  std::cout<<"end\n";
}
