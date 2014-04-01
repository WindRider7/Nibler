#ifndef _IASSISTANT_
# define _IASSISTANT_

#include <vector>

struct  grid
{
  unsigned int   x;
  unsigned int   y;

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
  virtual grid  setArea(const grid &area) = 0; // must set mapS_ aswell, and return it
  grid          getMapS() { return this->mapS_; }
  virtual void  drawEw() const = 0; // draw Empty Window
  virtual void  drawWa(const std::vector<grid> &s, const grid &f) const = 0;
  // i will remove this   ^
  virtual void  drawMap(const std::vector< std::vector<int> > &map) const = 0;

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
  virtual void  drawEw() const;
  virtual void  drawWa(const std::vector<grid> &s, const grid &f) const;
  // i will remove this   ^
  virtual void  drawMap(const std::vector< std::vector<int> > &map) const;

  virtual bool  escP() const;
  virtual bool  anyP() const;
};

#endif // !_IASSISTANT_
