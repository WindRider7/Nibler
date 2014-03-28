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
    grid          sReso_; // screen resolution
    grid          *cReso; // current resolution
    grid          map_; // 'case' resolution

	public:
		virtual grid  getReso() const = 0;
		virtual grid  getMap() const = 0;
		virtual void  init() const = 0;
};

// this ↓ class for testing purposes, do NOT look here.
class           GL : public IAssistant
{
public:
  GL();
	virtual grid  getReso() const;
	virtual grid  getMap() const;
	virtual void  init() const;

};

GL::GL()
{
  grid it;
  it.x = 1920;
  it.y = 1080;
  this->sReso_ = it;
}

grid  GL::getMap() const
{
  grid it;
  it.x = 30;
  it.y = 30;
	return it;
}

grid  GL::getReso() const
{
	return this->sReso_;
}

void  GL::init() const
{

}

#endif // !_IASSISTANT_
