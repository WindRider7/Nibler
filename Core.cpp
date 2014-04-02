#include "Core.hpp"

#include <ctime>
#include <cstdlib>
#include "MyTypes.hpp"
#include "Timer.hpp"

Core::Core() {}

Core::~Core() {}

bool  Core::sAlive()
{
  if (s_.front().x > mapS_.x || s_.front().y > mapS_.y
        || s_.front().x == 0 || s_.front().y == 0
        || sOn_ == 2)
    return false;
  else if (sOn_ == 1)
  {
    map_[sWas_.y][sWas_.x] = 2;
    s_.push_back(sWas_);
    generF();
    if (f_ == grid(0, 0))
      return false;
    return true;
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

void  Core::init(IAssistant *gl)
{
  std::list<grid>::iterator  it;

  dirInit();
  dLocked_ = false;
  mapS_ = gl->getMapS();
  map_.resize(mapS_.y + 2, std::vector<uint>(mapS_.x + 2, 0));

  s_.push_back(grid( mapS_.x - (mapS_.x / 2), mapS_.y - (mapS_.y / 2) ));
  it = s_.begin();
  for (uint i = 0; i != 3; ++i, ++it)
    s_.push_back(grid(it->x + 1, it->y));
  // init s_    ^
  for (it = s_.begin(); it != s_.end(); ++it) // store s_ to map_
    map_[it->y][it->x] = 2;
  srand(time(NULL));
  generF();
}

void    Core::goOn()
{
  std::list<grid>::iterator  it;
  grid  tmp;

  if (dir_[d_] == 's')
  {
    tmp.y = s_.front().y + 1;
    tmp.x = s_.front().x;
  }
  if (dir_[d_] == 'n')
  {
    tmp.y = s_.front().y - 1;
    tmp.x = s_.front().x;
  }
  if (dir_[d_] == 'e')
  {
    tmp.x = s_.front().x + 1;
    tmp.y = s_.front().y;
  }
  if (dir_[d_] == 'w')
  {
    tmp.x = s_.front().x - 1;
    tmp.y = s_.front().y;
  }

  map_[s_.back().y][s_.back().x] = 0;
  s_.push_front(tmp);
  sOn_ = map_[tmp.y][tmp.x];
  map_[tmp.y][tmp.x] = 2;
  sWas_ = s_.back();
  s_.pop_back();
}

void                Core::generF()
{
  std::vector<grid> range;
  uint              y;
  uint              x;

  for (y = 1; y != map_.size() - 1; ++y)
  {
    for (x = 1; x != map_[y].size() - 1; ++x)
    {
      if (map_[y][x] == 0)
        range.push_back(grid(x, y));
    }
  }
  if (range.size() == 0)
    f_ = grid(0, 0);
  x = rand() % range.size();
  f_ = range[x];
  map_[f_.y][f_.x] = 1;
}

int     Core::start(IAssistant *gl)
{
  Timer t;

  init(gl);
  gl->newWin(this->s_, this->f_);
  std::cout << "Press any key to start ..." << std::endl;
  while (!gl->anyP()); std::cout << " > Start" << std::endl;
  t.reset(1000);
  while (!gl->escP()) // main loop
  {
    if (gl->leftP() && !dLocked_)
      changeDir('<');
    if (gl->rightP() && !dLocked_)
      changeDir('>');
    if (t.isOut())
    {
      goOn();
      if (!sAlive())
        return 0;
      gl->drawWa(this->s_, this->f_);
      dLocked_ = false;
      t.reset(1000);
    }
  }
  return 1;
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
    if (d_ == 3)
      d = 0;
  }
  dLocked_ = true;
}
