void CInputParser::ParseInput()
{
  clickedOnLastFrame=false;
  SDL_Event e;
  while (SDL_PollEvent(&e)){
    int click_i,click_j;
    bool click=false; 
    //If user closes the window
    if (e.type == SDL_QUIT){
      quit = true;
    }
    //If user clicks the mouse
    if (e.type == SDL_MOUSEBUTTONDOWN){
      int mouseX,mouseY;
      SDL_GetMouseState(&mouseX,&mouseY);
      click_j=mouseX/60;
      click_i=mouseY/60;
      clickedOnLastFrame=false;
   }
  }
}

      


bool CInputParser::QuitRequested()
{
  return quit;
}
