#include "IAssistant.hpp"

#include <iostream>

GL::GL() {}

GL::~GL() {}

grid  GL::getReso()
{
  grid it;
  it.x = 1920;
  it.y = 1080;
	return it;
}

void  GL::drawWa(const std::vector<grid> &s_, const grid &f_) const {}

bool  GL::anyP() const {}

void  GL::init() {}

bool  GL::escP() const
{
  return true;
}

void  GL::drawEw() {}

grid  GL::setArea(const grid &area)
{
  this->areaS_ = area;
  this->mapS_.x = area.x / 2;
  this->mapS_.y = area.y / 2;
  return (this->mapS_);
}

//      /\
// this    file is for testing porposes
