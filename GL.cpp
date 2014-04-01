#include "IAssistant.hpp"

#include <iostream>

GL::GL() {}

GL::~GL() {}

grid  GL::getReso() const
{
  grid it;
  it.x = 1920;
  it.y = 1080;
	return it;
}

void  GL::drawWa(const std::vector<grid> &s, const grid &f) const
{
  std::vector<grid>::const_iterator it;

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

void  GL::drawEw() const {}

grid  GL::setArea(const grid &area)
{
  this->areaS_ = area;
  this->mapS_.x = area.x / 2;
  this->mapS_.y = area.y / 2;
  return (this->mapS_);
}

//      /\
// this    file is for testing porposes
