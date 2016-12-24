#ifndef CPLAYER_H
#define CPLAYER_H

class CPlayer{
protected:
public:
  virtual MakeMove();
}





class CHumanPlayer:public CPlayer{
}


class CComputerPlayer:public CPlayer{
}


#endif CPLAYER_H
