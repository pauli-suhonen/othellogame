#include "OthelloUtil.h"
#include "COthelloInstance.h"
#include <vector>
#include "CPlayer.h"
#include <iostream>

COthelloInstance::COthelloInstance(CPlayer* blackPlayer, CPlayer* whitePlayer)
{
  board =std::vector<std::vector<color>>(8,std::vector<color>(8,empty));
  board[3][3]=plr_white;
  board[3][4]=plr_black;
  board[4][4]=plr_white;
  board[4][3]=plr_black;
  playerInTurn=blackPlayer;
  playerNotInTurn=whitePlayer;
  std::cout<<"Fc\n";
  std::cout<<playerInTurn->plrColor<<"\n";
  FindValidMoves(playerInTurn->plrColor,board,validMoves, buttonsToFlip);
  std::cout<<"Sc\n";
  moveAcquired=false;
  moveI=0;
  moveJ=0;
}



bool COthelloInstance::SquareOccupiedByColor(color plr,int sqr_i,int sqr_j,std::vector<std::vector<color>> &board)
{
  if(board[sqr_i][sqr_j]==plr){
    return true;
  }else {
    return false;
  }
}

    

bool COthelloInstance::SquareOccupiedByOpponent(color plr,int sqr_i,int sqr_j,std::vector<std::vector<color>> &board)
{
  if(board[sqr_i][sqr_j]!=plr && board[sqr_i][sqr_j]!=empty){
    return true;
  }else {
    return false;
  }
}


bool COthelloInstance::PlayerInTurnGetMove()
{
  return playerInTurn->GetMove(moveI,moveJ);
}


  
bool COthelloInstance::PlayerInTurnUseMove()
{
  int buttonsToFlipIndex;
  std::cout<<"jee\n";
  std::cout<<moveI<<" "<<moveJ<<"\n";
  if (this->CheckForValidMove(moveI,moveJ,buttonsToFlipIndex,validMoves)){
    this->PlaceDisk(playerInTurn->plrColor,moveI,moveJ, board,buttonsToFlipIndex,buttonsToFlip);
    return true;
  }
  else
    return false;
}


void COthelloInstance::DetermineNewPlayerInTurn(){
  std::swap(playerInTurn,playerNotInTurn);
  FindValidMoves(playerInTurn->plrColor,board,validMoves, buttonsToFlip);
  if (validMoves.size()==0){
    std::swap(playerInTurn,playerNotInTurn);
    FindValidMoves(playerInTurn->plrColor,board,validMoves, buttonsToFlip);
  }
}




void COthelloInstance::FindValidMoves(color plr,const std::vector<std::vector<color>> &board,std::vector<int> &validMoves,std::vector<std::vector<int>> &buttonsToFlip)
{
  validMoves.clear();
  buttonsToFlip.clear();
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if (board[i][j]!=empty){
	continue;
      }
      std::vector<int> flipping;
      std::vector<int> flippingTemp;
      int ii,jj;

      //north
      flippingTemp.clear();
      ii=i-1;
      jj=j;
      while (ii>=0 && board[ii][jj]==OppositeColor(plr)){
	flippingTemp.push_back(ii*8+jj);
	ii=ii-1;
      }
      if(ii>=0 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }

      //northeast
      flippingTemp.clear();
      ii=i-1;
      jj=j+1;
      while (ii>=0 && jj<8 && board[ii][jj]==OppositeColor(plr)){
	flippingTemp.push_back(ii*8+jj);
	ii=ii-1;
	jj=jj+1;
      }
      if(ii>=0 && jj<8 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }

      
      
      //east
      flippingTemp.clear();
      ii=i;
      jj=j+1;
      while (jj<8 && board[ii][jj]==OppositeColor(plr)){
	flippingTemp.push_back(ii*8+jj);
	jj=jj+1;
      }
      if(jj<8 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }

      //southeast
      flippingTemp.clear();
      ii=i+1;
      jj=j+1;
      while (jj<8 && ii<8 &&board[ii][jj]==OppositeColor(plr)){
	flippingTemp.push_back(ii*8+jj);
	ii=ii+1;
	jj=jj+1;
      }
      if(jj<8 && ii<8 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }

      //south
      flippingTemp.clear();
      ii=i+1;
      jj=j;
      while (ii<8 && board[ii][jj]==OppositeColor(plr)){
	flippingTemp.push_back(ii*8+jj);
	ii=ii+1;
      }
      if(ii<8 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }



      //southwest
      flippingTemp.clear();
      ii=i+1;
      jj=j-1;
      while (ii<8 && jj>=0 && board[ii][jj]==OppositeColor(plr)){
	flippingTemp.push_back(ii*8+jj);
	ii=ii+1;
	jj=jj-1;
      }
      if(ii<8 && jj>=0 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }

      //west
      flippingTemp.clear();
      ii=i;
      jj=j-1;
      while (jj>=0 && board[ii][jj]==OppositeColor(plr)){
	flippingTemp.push_back(ii*8+jj);
	jj=jj-1;
      }
      if(jj>=0 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }

      //northwest
      flippingTemp.clear();
      ii=i-1;
      jj=j-1;
      while (jj>=0 && ii>=0 && board[ii][jj]==OppositeColor(plr)){
	flippingTemp.push_back(ii*8+jj);
	ii=ii-1;
	jj=jj-1;
      }
      if(jj>=0 && ii>=0 && board[ii][jj]==plr){
	flipping.insert(flipping.end(),flippingTemp.begin(),flippingTemp.end());
      }


      
      if(flipping.size()>0){
	validMoves.push_back(i*8+j);
	buttonsToFlip.push_back(flipping);
      }
    }
  }
  std::cout<<"validMoves.size():"<<validMoves.size()<<"\n";
}









void COthelloInstance::PlaceDisk(color plr,int sqr_i,int sqr_j, std::vector<std::vector<color>> &board,int buttonsToFlipIndex, std::vector<std::vector<int>> buttonsToFlip)
{
  board[sqr_i][sqr_j]=plr;
  for(std::vector<int>::iterator it=buttonsToFlip[buttonsToFlipIndex].begin();it!=buttonsToFlip[buttonsToFlipIndex].end();it++){
    board[*it/8][*it%8]=plr;
  }
 
}


bool COthelloInstance::CheckForValidMove(int i,int j,int &index,std::vector<int> &validMoves)
{
  std::cout<<"validMoves.size():"<<validMoves.size()<<"\n";
  for(index=0;index<validMoves.size();index++){
    if (validMoves[index]==(i*8+j)){
      std::cout<<"check_true\n";
      return true;
    }
  }
  std::cout<<"check_false\n";
  return false;
}
