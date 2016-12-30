#ifndef CPLAYER_H
#define CPLAYER_H
#include "OthelloUtil.h"
#include "CInputParser.h"

class CPlayer{
protected:
public:
  color plrColor;
  virtual bool GetMove();
};





class CHumanPlayer:public CPlayer{
 public:
  CInputParser *input;
  CHumanPlayer(CInputParser *param_input);
  bool GetMove(int &moveI, int &moveJ);
};


class CComputerPlayer:public CPlayer{
};


#endif
