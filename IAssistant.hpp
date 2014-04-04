#ifndef _IASSISTANT_
# define _IASSISTANT_

#include <vector>
#include <list>
#include "Tools.hpp"

class           IAssistant
{
protected:
  grid          mapS_; // work area resolution

public:
  virtual       ~IAssistant() {}

  virtual grid  setMapS(const grid &mapS) = 0;
  // ^ must return window max size in PX (depending on 'case' reso)
  virtual void  init() = 0;
  virtual grid  getReso() const = 0;
  virtual grid  getMapS() const { return this-> mapS_; }

  virtual void  newWin(const std::list<grid> &s, const grid &f) = 0;
  // create New Window  ^
  virtual void  drawWa(const std::list<grid> &s, const grid &f) = 0;
  // update map area  ^
  virtual bool  eventOccured() = 0;
  virtual bool  leftP() = 0;
  virtual bool  rightP() = 0;
  virtual bool  escP() = 0; // Esc pressed
  virtual bool  anyR() = 0; // any Key released! :O
};

#endif // !_IASSISTANT_
