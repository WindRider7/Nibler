#include "IAssistant.hpp"

GL::GL() {}

GL::~GL() {}

grid  GL::getReso() const
{
  grid it;
  it.x = 1920;
  it.y = 1080;
	return it;
}

void  GL::drawWa(const std::list<grid> &s, const grid &f)
{
  std::list<grid>::const_iterator it;

  for (it = s.begin(); it != s.end(); ++it)
  {
    std::cout << "x(" << (*it).x << "), y (" << (*it).y << ")" << std::endl;
  }
  std::cout << "-------" << std::endl;
}

bool  GL::anyP() const {}

void  GL::init() {}

bool  GL::escP() const
{
  return false;
}

void  GL::newWin(const std::list<grid> &s, const grid &f)
{
  std::list<grid>::const_iterator it;

  for (it = s.begin(); it != s.end(); ++it)
  {
    std::cout << "x(" << (*it).x << "), y (" << (*it).y << ")" << std::endl;
  }
  std::cout << "-------" << std::endl;
}

//bool  GL::pollEvent() const {}

grid  GL::setMapS(const grid &mapS)
{
  mapS_ = mapS;
  winMaxS_ = grid(mapS.x * 20, mapS.y * 20);
  return (winMaxS_);
}

bool  GL::leftP() const
{
  return false;
}

bool  GL::rightP() const
{
  return false;
}

//      /\
// this    file is for testing porposes
