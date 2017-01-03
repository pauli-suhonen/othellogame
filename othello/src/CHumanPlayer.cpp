#include "CHumanPlayer.h"
#include "CPlayer.h"
#include "OthelloUtil.h"
#include "CInputParser.h"


CHumanPlayer::CHumanPlayer(CInputParser *param_input,color param_plrColor):CPlayer(param_plrColor),input(param_input)
{}



bool CHumanPlayer::GetMove(std::vector<std::vector<color>> currentBoard,int &moveI, int &moveJ)
{
  (void)currentBoard;//Surpress unused warning
  if (input->clickedOnLastFrame){
    moveI=input->click_i;
    moveJ=input->click_j;
    return true;
  }
  return false;
}


