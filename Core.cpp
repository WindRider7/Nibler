#include "Core.hpp"
#include "Timer.hpp"

#include <iostream>

Core::Core() {}

Core::~Core() {}

bool  Core::sAlive()
{
  if (s_[0].x > mapS_.x || s_[0].y > mapS_.y
        || s_[0].x == 0 || s_[0].y == 0)
    return false;
  else
    return true;
}

void  Core::init(IAssistant *gl)
{
  dir_ = 'l';
  mapS_ = gl->getMapS();
  s_.push_back(grid( mapS_.x - (mapS_.x / 2), mapS_.y - (mapS_.y / 2) ));
  s_.push_back(grid(s_[0].x + 1, s_[0].y));
  s_.push_back(grid(s_[1].x + 1, s_[1].y));
  s_.push_back(grid(s_[2].x + 1, s_[2].y));
}

void    Core::goOn() // screeeewww 'this->'
{
  std::vector<grid>::iterator  it;
  grid  tmp;
  grid  z;

  if (dir_ == 'u')
  {
    tmp.y = s_[0].y + 1;
    tmp.x = s_[0].x;
  }
  if (dir_ == 'd')
  {
    tmp.y = s_[0].y - 1;
    tmp.x = s_[0].x;
  }
  if (dir_ == 'l')
  {
    tmp.x = s_[0].x - 1;
    tmp.y = s_[0].y;
  }
  if (dir_ == 'r')
  {
    tmp.x = s_[0].x + 1;
    tmp.y = s_[0].y;
  }
  for (it = s_.begin(); it != s_.end(); ++it)
  {
    z = *it;
    *it = tmp;
    tmp = z;
  }
}

int     Core::start(IAssistant *gl)
{
  Timer t;

  init(gl);
  gl->drawEw();
  gl->drawWa(this->s_, this->f_);
  std::cout << "Press any key to start ..." << std::endl;
  while (!gl->anyP()); std::cout << " > Start" << std::endl;
  while (!gl->escP())
  {
    if (t.isOut())
    {
      goOn();
      if (!sAlive())
        return 0;
      gl->drawWa(this->s_, this->f_);
      t.reset(1000);
    }
  }
  return 1;
}
