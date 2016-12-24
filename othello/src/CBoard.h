#ifndef CBOARD_H
#define CBOARD_H


class CBoard(){
 protected:
 public:
  
  bool SquareOccupiedByColor(color plr,int sqr_i,int sqr_j,std::vector<std::vector<color>> &board);
  bool SquareOccupiedByOpponent(color plr,int sqr_i,int sqr_j,std::vector<std::vector<color>> &board);
  void FindValidMoves(color plr,const std::vector<std::vector<color>> &board,std::vector<int> &validMoves,std::vector<std::vector<int>> &buttonsToFlip);
    void PlaceButton(color plr,int sqr_i,int sqr_j, std::vector<std::vector<color>> &board,int buttonsToFlipIndex, std::vector<std::vector<int>> buttonsToFlip);
}
bool CheckForValidMove(int i,int j,int &index,std::vector<int> &validMoves);


#endif
