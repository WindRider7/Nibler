#ifndef _IASSISTANT_
# define _IASSISTANT_

#include <vector>
#include <list>

typedef unsigned int  uint;

struct  grid
{
  uint  x;
  uint  y;

  grid() : x(0), y(0) {}
  grid(int xx, int yy) : x(xx), y(yy) {}
};

class           IAssistant
{
protected:
  grid          areaS_; // 'px' area resolution
  grid          mapS_; // 'case' resolution

public:
  virtual       ~IAssistant() {}

  virtual void  init() = 0;
  virtual grid  getReso() const = 0;

  virtual grid  setArea(const grid &area) = 0;
  //  ^  must set mapS_ aswell, and return it
  grid          getMapS() const { return this->mapS_; }

  virtual void  newWin(const std::list<grid> &s, const grid &f) = 0;
  // create New Window  ^

  virtual void  drawWa(const std::list<grid> &s, const grid &f) = 0;
  // update work area  ^

  virtual bool  escP() const = 0; // Esc pressed
  virtual bool  anyP() const = 0; // any Key pressed
};

// this     class for testing purposes
//       \/
class           GL : public IAssistant
{
public:
  GL();
  virtual ~GL();

  virtual void  init();
	virtual grid  getReso() const;
  virtual grid  setArea(const grid &area);
  virtual void  newWin(const std::list<grid> &s, const grid &f);
  virtual void  drawWa(const std::list<grid> &s, const grid &f);

  virtual bool  escP() const;
  virtual bool  anyP() const;
};

#endif // !_IASSISTANT_
