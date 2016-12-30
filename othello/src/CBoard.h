#ifndef CBOARD_H
#define CBOARD_H

#include "CPlayer.h"



class CBoard{
  int moveNro;
  Player* playerInTurn;
  bool moveAcquired;
  int moveI;
  int moveJ;
  std::vector<int> validMoves;
  std::vector<std::vector<int>> buttonsToFlip;
 public:
  CBoard CBoard(CPlayer* blackPlayer, Cplayer* whitePlayer);
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
