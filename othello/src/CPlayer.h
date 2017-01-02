#ifndef CPLAYER_H
#define CPLAYER_H
#include "OthelloUtil.h"
#include "CInputParser.h"

class CPlayer{
protected:
public:
  CPlayer(color);
  color plrColor;
  virtual bool GetMove(int &moveI,int &moveJ)=0;
};



#endif
