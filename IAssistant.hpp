#ifndef _IASSISTANT_
# define _IASSISTANT_

struct  grid
{
  int   x;
  int   y;
};

class             IAssistant
{
protected:
  grid          area_; // game area resolution
  grid          map_; // 'case' resolution

public:
  virtual       ~IAssistant() {}

  virtual grid  getReso() const = 0;
  virtual void  init() const = 0;
  virtual grid  setArea(grid &it) = 0; // must set map_ aswell, and return it
  grid          getMap() { return this->map_; }
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
