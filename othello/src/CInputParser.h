#ifndef CINPUTPARSER_H
#define CINPUTPARSER_H

class CInputParser
{
  bool quit;
public:
  void ParseInput();
  bool QuitRequested();
  bool clickedOnLastFrame;
  int click_j;
  int click_i;
}










#endif
