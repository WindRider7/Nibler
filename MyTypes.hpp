#ifndef _MYTYPES_H_
# define _MYTYPES_H_

#include <iostream>

typedef unsigned int  uint;

struct                grid
{
  uint                x;
  uint                y;

  grid();
  grid(int xx, int yy);

  bool                operator==(grid const &other);
  grid&               operator=(grid const &other);
};

std::ostream&         operator<<(std::ostream &os, grid const &other);

#endif // !_MYTYPES_H_
