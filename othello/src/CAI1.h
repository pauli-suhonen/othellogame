#ifndef CAI1_H
#define CAI1_H

#include "CAI.h"
#include "OthelloUtil.h"
#include <vector>

class CAI1:public CAI{
protected:
public:
  CAI1();
  void EvaluateMove(int*,int*,bool*,std::vector<std::vector<color>> currentBoard,color);
  void FindValidMoves(color plr,const std::vector<std::vector<color>> &board,std::vector<int> &validMoves,std::vector<std::vector<int>> &buttonsToFlip);

};


#endif
