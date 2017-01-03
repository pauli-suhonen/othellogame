#ifndef CPLAYER_H
#define CPLAYER_H
#include "OthelloUtil.h"
#include "CInputParser.h"
#include <vector>

class CPlayer{
protected:
public:
  CPlayer(color);
  color plrColor;
  virtual bool GetMove(std::vector<std::vector<color>> currentBoard,int &moveI,int &moveJ)=0;
};



#endif
