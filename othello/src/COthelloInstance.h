#ifndef COHELLOINSTANCE_H
#define COHELLOINSTANCE_H

#include "OthelloUtil.h"
#include "CPlayer.h"
#include <vector>



class COthelloInstance{
 public:
  std::vector<std::vector<color>> board;
  int moveNro;
  CPlayer* playerInTurn;
  CPlayer* playerNotInTurn;
  bool moveAcquired;
  int moveI;
  int moveJ;
  std::vector<int> validMoves;
  std::vector<std::vector<int>> buttonsToFlip;
 public:
  COthelloInstance(CPlayer* blackPlayer, CPlayer* whitePlayer);
  bool SquareOccupiedByColor(color plr,int sqr_i,int sqr_j,std::vector<std::vector<color>> &board);
  bool SquareOccupiedByOpponent(color plr,int sqr_i,int sqr_j,std::vector<std::vector<color>> &board);
  void FindValidMoves(color plr,const std::vector<std::vector<color>> &board,std::vector<int> &validMoves,std::vector<std::vector<int>> &buttonsToFlip);
  void PlaceDisk(color plr,int sqr_i,int sqr_j, std::vector<std::vector<color>> &board,int buttonsToFlipIndex, std::vector<std::vector<int>> buttonsToFlip);
  bool PlayerInTurnGetMove();
  bool PlayerInTurnUseMove();
  void DetermineNewPlayerInTurn();
  bool CheckForValidMove(int i,int j,int &index,std::vector<int> &validMoves);
};



#endif
