#include "CAI.h"
#include "CAI1.h"
#include <iostream>



CAI1::CAI1()
{
}

void CAI1::EvaluateMove(int *evaluatedMoveI,int *evaluatedMoveJ,bool *evaluationReady,std::vector<std::vector<color>> currentBoard,color plrColor)
{
  std::vector<int> validMoves;
  std::vector<std::vector<int>> buttonsToFlip;
  FindValidMoves(plrColor,currentBoard,validMoves,buttonsToFlip);
  std::cout<<plrColor<<"\n";
  std::cout<<"validMoves.size()asdf:"<<validMoves.size()<<"\n";
  *evaluatedMoveI=validMoves[0]/8;
  *evaluatedMoveJ=validMoves[0]%8;
  *evaluationReady=true;
}



void CAI1::FindValidMoves(color plr,const std::vector<std::vector<color>> &board,std::vector<int> &validMoves,std::vector<std::vector<int>> &buttonsToFlip)
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

