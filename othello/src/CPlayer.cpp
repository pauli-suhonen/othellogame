#inlude "CInputParser.h"

bool CHumanPlayer::CHumanPlayer(CInputParser *param_input)
{
  input=param_input;
}



CHumanPlayer::GetMove(int &moveI, int &moveJ)
{
  if (input.clickedOnLastFrame){
    int buttonsToFlipIndex;
    moveI=input.click_i;
    moveJ=input.click_j;
    return true;
  }
  return false;
}




      


    


