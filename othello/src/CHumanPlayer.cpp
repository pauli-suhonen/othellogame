#include "CHumanPlayer.h"
#include "CPlayer.h"
#include "OthelloUtil.h"
#include "CInputParser.h"


CHumanPlayer::CHumanPlayer(CInputParser *param_input,color param_plrColor):input(param_input),CPlayer(param_plrColor)
{}



bool CHumanPlayer::GetMove(int &moveI, int &moveJ)
{
  if (input->clickedOnLastFrame){
    moveI=input->click_i;
    moveJ=input->click_j;
    return true;
  }
  return false;
}


