#ifndef CHUMANPLAYER_H
#define CHUMANPLAYER_H

#include "CPlayer.h"
#include "OthelloUtil.h"

class CHumanPlayer:public CPlayer{
 public:
  CInputParser *input;
  CHumanPlayer(CInputParser *param_input,color);
  bool GetMove(int &moveI, int &moveJ);
};


class CComputerPlayer:public CPlayer{
};

#endif
