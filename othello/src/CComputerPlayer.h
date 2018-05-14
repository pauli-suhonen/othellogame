#ifndef CCOMPUTERPLAYER_H
#define CCOMPUTERPLAYER_H

#include "CPlayer.h"
#include "OthelloUtil.h"
#include "COthelloInstance.h"
#include "CAI.h"


class CComputerPlayer:public CPlayer{
  CAI *ai;
  int evaluatedMoveI;
  int evaluatedMoveJ;
 public:
  bool  moveRequested;
  bool evaluationReady;
  CInputParser *input;
  CComputerPlayer(color);
  void SetAI(CAI *);
  bool GetMove(std::vector<std::vector<color>> currentBoard,int &moveI, int &moveJ);
  void EvaluateNextMove(std::vector<std::vector<color>> currentBoard);
};





#endif
