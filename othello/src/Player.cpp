



bool CHumanPlayer:MakeMove(CInputParser input)
{
  if (input.clickedOnLastFrame){
    int buttonsToFlipIndex;
    if (CheckForValidMove(input.click_i,input.click_j,buttonsToFlipIndex,validMoves)){
      PlaceButton(colorInTurn,input.click_i,input.click_j, board,buttonsToFlipIndex,buttonsToFlip);
      colorInTurn=OppositeColor(colorInTurn);
      FindValidMoves(colorInTurn,board,validMoves, buttonsToFlip);
      if(validMoves.size()==0){
	colorInTurn=OppositeColor(colorInTurn);
	FindValidMoves(colorInTurn,board,validMoves, buttonsToFlip);
      }
    }	
  }
}

bool CComputerPlayer:MakeMove(CInputParser input)
{
  if (input.clickedOnLastFrame){
    int buttonsToFlipIndex;
    if (CheckForValidMove(input.click_i,input.click_j,buttonsToFlipIndex,validMoves)){
      PlaceButton(colorInTurn,input.click_i,input.click_j, board,buttonsToFlipIndex,buttonsToFlip);
      colorInTurn=OppositeColor(colorInTurn);
      FindValidMoves(colorInTurn,board,validMoves, buttonsToFlip);
      if(validMoves.size()==0){
	colorInTurn=OppositeColor(colorInTurn);
	FindValidMoves(colorInTurn,board,validMoves, buttonsToFlip);
      }
    }	
  }
}



      


    


