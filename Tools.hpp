#ifndef _TOOLS_H_
# define _TOOLS_H_

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
void                  myExit(int s);

#endif // !_TOOLS_H_
