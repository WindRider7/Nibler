#ifndef _IASSISTANT_
# define _IASSISTANT_

#include <vector>
#include <list>
#include "MyTypes.hpp"

class           IAssistant
{
protected:
  grid          mapS_; // work area resolution

public:
  virtual       ~IAssistant() {}

  virtual void  init() = 0;
  virtual grid  getReso() const = 0;

  virtual grid  setMapS(const grid &mapS) = 0;
  // ^ must return window max size in PX (depending on 'case' reso)
  virtual grid  getMapS() const { return this-> mapS_; }

  virtual void  newWin(const std::list<grid> &s, const grid &f) = 0;
  // create New Window  ^
  virtual void  drawWa(const std::list<grid> &s, const grid &f) = 0;
  // update work area  ^

  //virtual bool  pollEvent() const = 0;
  virtual bool  leftP() const = 0;
  virtual bool  rightP() const = 0;
  virtual bool  escP() const = 0; // Esc pressed
  virtual bool  anyP() const = 0; // any Key pressed
};

// this     class for testing purposes
//       \/
class           GL : public IAssistant
{
private:
  grid          winMaxS_; // window max size

public:
  GL();
  virtual ~GL();

  virtual void  init();
	virtual grid  getReso() const;
  virtual grid  setMapS(const grid &mapS);
  virtual void  newWin(const std::list<grid> &s, const grid &f);
  virtual void  drawWa(const std::list<grid> &s, const grid &f);
  //virtual bool  pollEvent() const;

  virtual bool  escP() const;
  virtual bool  anyP() const;
  virtual bool  leftP() const;
  virtual bool  rightP() const;
};

#endif // !_IASSISTANT_
