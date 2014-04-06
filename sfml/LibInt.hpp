#ifndef _LIBINT_H_
# define _LIBINT_H_

#include <vector>
#include <list>
#include "Tools.hpp"

class           LibInt
{
protected:
  grid          mapS_; // work area resolution

public:
  grid          getMapS() const { return this-> mapS_; }
  virtual       ~LibInt() {}
  virtual bool  eventOccured() { return true; }

  virtual grid  setMapS(const grid &mapS) = 0; // < Init Start
  // ^ must return window max size in PX (depending on 'case' reso)
  virtual void  init() = 0;
  virtual grid  getReso() const = 0;
  
  virtual void  newWin(const std::vector< std::vector<int> > &map) = 0;
  // create New Window ^                          ^ Init End

  virtual void  drawWa(const std::vector< std::vector<int> > &map) = 0;
  // update map area ^
  virtual bool  leftP() = 0;
  virtual bool  anyP() = 0;
  virtual bool  rightP() = 0;
  virtual bool  escP() = 0; // Esc pressed
  virtual bool  anyR() = 0; // any Key released! :O
};

#endif // !_LIBINT_H_
