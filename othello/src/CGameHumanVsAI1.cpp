#include "CGameHumanVsAI1.h"
#include "OthelloUtil.h"
#include "CInputParser.h"
#include "CBoardGUI.h"
#include "CPlayer.h"
#include "CComputerPlayer.h"
#include "CHumanPlayer.h"
#include "COthelloInstance.h"
#include "SDL.h"
#include "CAI.h"
#include "CAI1.h"

CGameHumanVsAI1::CGameHumanVsAI1():
  player1(CHumanPlayer(&boardGui.input,plr_black)),
  player2(CComputerPlayer(plr_white)),
  gameInstance(COthelloInstance(&player1,&player2))
  
{
  CAI1 ai;
  CAI1* p_CAI=&ai;  
  player2.SetAI(p_CAI);
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
