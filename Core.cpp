#include "Core.hpp"
#include "Timer.hpp"

#include <iostream>

Core::Core() {}

Core::~Core() {}

bool  Core::sAlive()
{
  if (s_.front().x > mapS_.x || s_.front().y > mapS_.y
        || s_.front().x == 0 || s_.front().y == 0)
    return false;
  else
    return true;
}

void  Core::init(IAssistant *gl)
{
  std::list<grid>::iterator  it;

  dir_ = 'l';
  mapS_ = gl->getMapS();
  map_.resize(mapS_.y + 1, std::vector<int>(mapS_.x + 1, 0));
  s_.push_back(grid( mapS_.x - (mapS_.x / 2), mapS_.y - (mapS_.y / 2) ));
  it = s_.begin();
  for (uint i = 0; i != 3; ++i, ++it) // init s_
    s_.push_back(grid(it->x + 1, it->y));
  for (it = s_.begin(); it != s_.end(); ++it) // store s_ to map_
    map_[it->y][it->x] = 2;
}

void    Core::goOn()
{
  std::list<grid>::iterator  it;
  grid  tmp;
  grid  z;

  if (dir_ == 'u')
  {
    tmp.y = s_.front().y + 1;
    tmp.x = s_.front().x;
  }
  if (dir_ == 'd')
  {
    tmp.y = s_.front().y - 1;
    tmp.x = s_.front().x;
  }
  if (dir_ == 'l')
  {
    tmp.x = s_.front().x - 1;
    tmp.y = s_.front().y;
  }
  if (dir_ == 'r')
  {
    tmp.x = s_.front().x + 1;
    tmp.y = s_.front().y;
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
  gl->newWin(this->s_, this->f_);
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
