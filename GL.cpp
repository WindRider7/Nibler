#include "IAssistant.hpp" // this file is for testing porposes

GL::GL()
{

}

GL::~GL()
{

}

grid  GL::getReso()
{
  grid it;
  it.x = 1920;
  it.y = 1080;
	return it;
}

void  GL::draw(const std::vector<grid> &s_, const grid &f_) const
{

}

void  GL::init()
{

}

grid  GL::setArea(const grid &area)
{
  this->areaS_ = area;
  this->mapS_.x = area.x / 2;
  this->mapS_.y = area.y / 2;
  return (this->mapS_);
}
