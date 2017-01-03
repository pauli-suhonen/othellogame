#include "CComputerPlayer.h"
#include "CPlayer.h"
#include "OthelloUtil.h"
#include "AI1.h"


CComputerPlayer::CComputerPlayer(color param_plrColor):CPlayer(param_plrColor)
{
  moveRequested=false;
  evaluationReady=false;
}



bool CComputerPlayer::GetMove(std::vector<std::vector<color>> currentBoard,int &moveI, int &moveJ)
{
  if (moveRequested){
    if(evaluationReady){
      moveRequested=false;
      evaluationReady=false;
      moveI=evaluatedMoveI;
      moveJ=evaluatedMoveJ;
      return true;
    }
    else{
      return false;
    }
  }
  else {
    moveRequested=true;
    EvaluateNextMove(currentBoard);
    return false;
  }
}






void CComputerPlayer::EvaluateNextMove(std::vector<std::vector<color>> currentBoard)
{
  AI1 evaluationAI(&evaluatedMoveI,&evaluatedMoveJ,&evaluationReady,currentBoard,plrColor);
}
