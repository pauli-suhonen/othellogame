#include "OthelloUtil.h"

color OppositeColor(color plr)
{
  if (plr==plr_white){
    return plr_black;
  }
  else if (plr==plr_black){
    return plr_white;
  }
  return empty;//to surpress warning
}
