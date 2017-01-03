#ifndef CCOMPUTERPLAYER_H
#define CCOMPUTERPLAYER_H

#include "CPlayer.h"
#include "OthelloUtil.h"
#include "COthelloInstance.h"


class CComputerPlayer:public CPlayer{
  int evaluatedMoveI;
  int evaluatedMoveJ;
 public:
  bool  moveRequested;
  bool evaluationReady;
  CInputParser *input;
  CComputerPlayer(color);
  bool GetMove(std::vector<std::vector<color>> currentBoard,int &moveI, int &moveJ);
  void EvaluateNextMove(std::vector<std::vector<color>> currentBoard);
};





#endif
