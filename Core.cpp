#include "Core.hpp"
#include "Timer.hpp"

Core::Core() {}

Core::~Core() {}

void  Core::init(IAssistant *gl)
{
  int i = 0;

  this->dir_ = 'a';
  this->mapS_ = gl->getMap();
  this->s_.push_back(grid(this->mapS_.x, this->mapS_.y / 2));
}

void    Core::start(IAssistant *gl)
{
  Timer t;

  init(gl);
}
