#ifndef CGAMEAI1VSAI1_H
#define CGAMEAI1VSAI1_H

#include "CPlayer.h"
#include "CComputerPlayer.h"
#include "COthelloInstance.h"
#include "CBoardGUI.h"


class CGameAI1VsAI1{
 public:
  CGameAI1VsAI1();
 private:
  CBoardGUI boardGui;
  CComputerPlayer player1;
  CComputerPlayer player2;
  COthelloInstance gameInstance;
};


#endif
