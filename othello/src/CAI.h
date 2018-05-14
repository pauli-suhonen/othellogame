#ifndef CAI_H
#define CAI_H
#include "OthelloUtil.h"
#include <vector>

class CAI{
protected:
public:
  CAI();
  virtual void EvaluateMove(int*,int*,bool*,std::vector<std::vector<color>> currentBoard,color)=0;
};



#endif
