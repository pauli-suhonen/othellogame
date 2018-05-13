#include<iostream>
#include <string>
#include <vector>
#include "CGameHumanVsAI1.h"


int main()
{
  while (1){
    std::cout<<"Othello game\n";
    std::cout<<"1: human vs human\n";
    std::cout<<"2: human vs AI1\n";
    std::cout<<"3: AI1 vs AI1\n";
    std::cout<<"4: AI breed\n";
    std::cout<<"5: quit\n";
    std::cout<<"Select mode:";
    int mode=0;
    while (!(mode==1 ||mode==2 || mode==3 || mode==4 || mode==5)){
      std::cin>>mode;
    }
    if (mode==2){
      CGameHumanVsAI1 game;
    }
    if (mode==5){
      return 0;
    }
  }
}


