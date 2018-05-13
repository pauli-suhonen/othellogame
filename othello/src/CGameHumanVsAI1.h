#ifndef CGAMEHUMANVSAI1_H
#define CGAMEHUMANVSAI1_H

#include "CPlayer.h"
#include "CComputerPlayer.h"
#include "CHumanPlayer.h"
#include "COthelloInstance.h"
#include "CBoardGUI.h"


class CGameHumanVsAI1{
 public:
  CGameHumanVsAI1();
 private:
  CBoardGUI boardGui;
  CHumanPlayer player1;
  CComputerPlayer player2;
  COthelloInstance gameInstance;
};


#endif
