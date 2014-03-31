#ifndef _IASSISTANT_
# define _IASSISTANT_

#include <vector>

struct  grid
{
  int   x;
  int   y;

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
  virtual grid  getReso() = 0;
  virtual grid  setArea(const grid &area) = 0; // must set mapS_ aswell, and return it
  grid          getMapS() { return this->mapS_; }
  virtual void  drawEw() = 0; // draw Empty Window
  virtual void  drawWa(const std::vector<grid> &s_, const grid &f_) const = 0;
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
	virtual grid  getReso();
  virtual grid  setArea(const grid &area);
  virtual void  drawEw();
  virtual void  drawWa(const std::vector<grid> &s_, const grid &f_) const;

  virtual bool  escP() const;
  virtual bool  anyP() const;
};

#endif // !_IASSISTANT_
