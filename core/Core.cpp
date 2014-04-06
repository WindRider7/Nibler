#include "Core.hpp"

#include <ctime> // time
#include <cstdlib> // random
#include "Tools.hpp"
#include "Timer.hpp"

Core::Core() {}

Core::~Core() {}

bool  Core::sAlive() const
{
  if (sOn_.x == mapS_.x || sOn_.y == mapS_.y || sOn_.x == -1     
    || sOn_.y == -1 || map_[sOn_.y][sOn_.x] == 2)
  {
    return false;
  }
  else
    return true;
}

void  Core::dirInit()
{
  dir_.push_back('w');
  dir_.push_back('n');
  dir_.push_back('e');
  dir_.push_back('s');
  d_ = 0;
}

void  Core::init(LibInt *gl)
{
  std::list<grid>::iterator  it;

  dirInit();
  dLocked_ = false;
  mapS_ = gl->getMapS();
  map_.resize(mapS_.y, std::vector<int>(mapS_.x, 0));

  s_.push_back(grid( mapS_.x - (mapS_.x / 2), mapS_.y - (mapS_.y / 2) ));
  it = s_.begin();
  for (int i = 0; i != 3; ++i, ++it)
    s_.push_back(grid(it->x + 1, it->y));
  // init s_    ^
  map_[s_.front().y][s_.front().x] = 3;
  map_[s_.front().y][s_.front().x + 1] = 2;
  map_[s_.front().y][s_.front().x + 2] = 2;
  map_[s_.front().y][s_.front().x + 3] = 4;
  srand(time(NULL));
  generF();
}

void    Core::tryToGo()
{
  if (dir_[d_] == 's')
  {
    sOn_.y = s_.front().y + 1;
    sOn_.x = s_.front().x;
  }
  if (dir_[d_] == 'n')
  {
    sOn_.y = s_.front().y - 1;
    sOn_.x = s_.front().x;
  }
  if (dir_[d_] == 'e')
  {
    sOn_.x = s_.front().x + 1;
    sOn_.y = s_.front().y;
  }
  if (dir_[d_] == 'w')
  {
    sOn_.x = s_.front().x - 1;
    sOn_.y = s_.front().y;
  }
}

bool                Core::generF()
{
  std::vector<grid> range;
  int               y;
  int               x;


  for (y = 0; y != mapS_.y; ++y)
  {
    for (x = 0; x != mapS_.x; ++x)
    {
      if (map_[y][x] == 0)
        range.push_back(grid(x, y));
    }
  }
  if (range.size() == 0)
    return false;
  x = rand() % range.size();
  map_[range[x].y][range[x].x] = 1;
  return true;
}

void    Core::goOn()
{
  std::list<grid>::iterator  it;
  int   y;
  int   x;
  int   s;

  s = map_[sOn_.y][sOn_.x];
  map_[s_.front().y][s_.front().x] = 2;
  map_[sOn_.y][sOn_.x] = 3;
  s_.push_front(sOn_);
  if (s == 4)
  {
    s_.pop_back();
    map_[s_.back().y][s_.back().x] = 4;
  }
  else if (s != 1)
  {
    map_[s_.back().y][s_.back().x] = 0;
    s_.pop_back();
    map_[s_.back().y][s_.back().x] = 4;
  }
  else
  {
    map_[s_.back().y][s_.back().x] = 4;
    it = s_.end(); --it; --it;
    map_[it->y][it->x] = 2;
    generF();
  }
}

int     Core::start(LibInt *gl)
{
  Timer t;

  init(gl);
  gl->newWin(map_);
  std::cout << "Press any key to start ..." << std::endl;
  while (!gl->anyR())
    gl->drawWa(map_);
  std::cout << " > Start" << std::endl;
  while (42) // main loop
  {
    if (gl->eventOccured())
    {
      if (gl->escP())
        break;
      if (gl->xPressed())
        break;
      if (gl->leftP() && !dLocked_)
        changeDir('<');
      if (gl->rightP() && !dLocked_)
        changeDir('>');
    }
    if (t.isOut())
    {
      tryToGo();
      if (!sAlive())
      {
        std::cout << "Game Over !" << std::endl;
        std::cout << "Press any key to exit ..." << std::endl;
        while (!gl->anyP())
          gl->drawWa(map_);
        while (!gl->anyR())
          gl->drawWa(map_);
        return -1;
      }
      goOn();
      dLocked_ = false;
      t.reset(70000);
    }
    gl->drawWa(map_);
  }
  std::cout << "Esc or (x) pressed ..." << std::endl;
  return 0;
}

void  Core::changeDir(char d)
{
  if (d == '<')
  {
    --d_;
    if (d_ == -1)
      d_ = 3;
  }
  if (d == '>')
  {
    ++d_;
    if (d_ == 4)
      d_ = 0;
  }
  dLocked_ = true;
}
