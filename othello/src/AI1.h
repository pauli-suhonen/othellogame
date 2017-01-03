#ifndef AI1_H
#define AI1_H

#include "OthelloUtil.h"
#include <vector>

class AI1{
protected:
public:
  AI1(int*,int*,bool*,std::vector<std::vector<color>> currentBoard,color);
  void FindValidMoves(color plr,const std::vector<std::vector<color>> &board,std::vector<int> &validMoves,std::vector<std::vector<int>> &buttonsToFlip);

};


#endif
