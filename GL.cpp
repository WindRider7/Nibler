#include "IAssistant.hpp" // dis file is for testing porposes

GL::GL()
{

}

GL::~GL()
{

}

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

grid  GL::setArea(grid &it)
{
  this->areaS_ = it;
  this->mapS_.x = it.x / 2;
  this->mapS_.y = it.y / 2;
  return (this->mapS_);
}
