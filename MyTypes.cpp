#include "MyTypes.hpp"

grid::grid() : x(0), y(0) {}
grid::grid(int xx, int yy) : x(xx), y(yy) {}

bool          grid::operator==(grid const &other)
{
  if (other.x == this->x && other.y == this->y)
    return true;
  else
    return false;
}

grid&         grid::operator=(grid const &other)
{
  if (&other != this)
  {
    this->x = other.x;
    this->y = other.y;
  }
  return *this;
}

std::ostream& operator<<(std::ostream &os, grid const &other)
{
  os << "x(" << other.x << "), y(" << other.y << ")";
  return os;
}
