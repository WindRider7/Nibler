#ifndef _IASSISTANT_
# define _IASSISTANT_

struct grid
{
  int x;
  int y;
};

class IAssistant
{
	public:
		virtual grid getReso() const = 0;
		virtual void init() const = 0;
};

#endif // !_IASSISTANT_

class GL : public IAssistant
{
public:
	virtual grid getReso() const;
	virtual void init() const;

};

grid  GL::getReso() const
{
  grid it;
  it.x = 1920;
  it.y = 1080;
	return it;
}

void  GL::init() const
{

}
