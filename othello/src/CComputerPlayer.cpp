#include "CComputerPlayer.h"
#include "CPlayer.h"
#include "OthelloUtil.h"
#include "CAI.h"
#include "CAI1.h"


CComputerPlayer::CComputerPlayer(color param_plrColor):CPlayer(param_plrColor)
{
  moveRequested=false;
  evaluationReady=false;
}

void CComputerPlayer::SetAI(CAI* param_ai)
{
  ai=param_ai;
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
  ai->EvaluateMove(&evaluatedMoveI,&evaluatedMoveJ,&evaluationReady,currentBoard,plrColor);
}

