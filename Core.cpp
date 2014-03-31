#include "Core.hpp"
#include "Timer.hpp"

Core::Core() {}

Core::~Core() {}

void  Core::init(IAssistant *gl)
{
  int i = 0;

  this->dir_ = 'a';
  this->mapS_ = gl->getMap();
  this->map_.resize(this->mapS_.y, std::vector<int>(this->mapS_.x, 0));
  this->s_.push_back(grid(this->mapS_.x / 2, this->mapS_.y / 2));
}

void    Core::start(IAssistant *gl)
{
  Timer t;

  init(gl);
}
