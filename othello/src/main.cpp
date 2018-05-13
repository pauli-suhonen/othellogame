int main()
{
  CBoardGUI boardGui();
  CHumanPlayer player1(&boardGui.input,plr_black);
  CComputerPlayer player2(plr_white);
  COthelloInstance gameInstance(&player1,&player2);

  while (!boardGui.input.QuitRequested() && !gameInstance.gameEnded){
    boardGui.input.ParseInput();
    if(gameInstance.PlayerInTurnGetMove()){
      if(gameInstance.PlayerInTurnUseMove()){
	gameInstance.DetermineNewPlayerInTurn();
      }
    }
    boardGui.Render(gameInstance.board);
  }
  cleanup( blackbutton,whitebutton,emptysquare, renderer, window);
  IMG_Quit();
  SDL_Quit();
  std::cout<<"end\n";
}


