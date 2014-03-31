#ifndef _IASSISTANT_
# define _IASSISTANT_

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

  virtual grid  getReso() const = 0;
  virtual void  init() const = 0;
  virtual grid  setArea(grid &area) = 0; // must set mapS_ aswell, and return it
  grid          getMap() { return this->mapS_; }
};

// this ↓ class for testing purposes, do NOT look here.
class           GL : public IAssistant
{
public:
  GL();
  virtual ~GL();

  virtual grid  setArea(grid &it);
	virtual grid  getReso() const;
	virtual void  init() const;

};

#endif // !_IASSISTANT_
