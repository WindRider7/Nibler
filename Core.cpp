#include "Core.hpp"
#include "Timer.hpp"

#include <iostream>

Core::Core() {}

Core::~Core() {}

void  Core::init(IAssistant *gl)
{
  int i = 0;

  this->dir_ = 'a';
  this->mapS_ = gl->getMapS();
  this->s_.push_back(grid(this->mapS_.x, this->mapS_.y / 2));
}

void    Core::goOn()
{

}

void    Core::start(IAssistant *gl)
{
  Timer t;

  init(gl);
  gl->drawEw();
  std::cout << "Press any key to start ..." << std::endl;
  while(!gl->anyP()); std::cout << " > Start" << std::endl;
  while (!gl->escP())
  {
    if (t.isOut())
    {
      goOn();
      gl->drawWa(this->s_, this->f_);
      t.reset(1000);
    }
  }
  std::cout << "Esc pressed..." << std::endl;
}
