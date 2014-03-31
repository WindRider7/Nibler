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
  grid          areaS_; // game area resolution
  grid          mapS_; // 'case' resolution

public:
  virtual       ~IAssistant() {}

  virtual void  init() = 0;
  virtual grid  getReso() = 0;
  virtual grid  setArea(const grid &area) = 0; // must set mapS_ aswell, and return it
  grid          getMap() { return this->mapS_; }
  virtual void  draw(const std::vector<grid> &s_, const grid &f_) const = 0;
};

// this     class for testing purposes, do NOT look here.
//       \/
class           GL : public IAssistant
{
public:
  GL();
  virtual ~GL();

  virtual void  init();
	virtual grid  getReso();
  virtual grid  setArea(const grid &area);
  virtual void  draw(const std::vector<grid> &s_, const grid &f_) const;

};

#endif // !_IASSISTANT_
