#ifndef CGAMEHUMANVSHUMAN_H
#define CGAMEHUMANVSHUMAN_H

#include "CPlayer.h"
#include "CHumanPlayer.h"
#include "COthelloInstance.h"
#include "CBoardGUI.h"


class CGameHumanVsHuman{
 public:
  CGameHumanVsHuman();
 private:
  CBoardGUI boardGui;
  CHumanPlayer player1;
  CHumanPlayer player2;
  COthelloInstance gameInstance;
};


#endif
