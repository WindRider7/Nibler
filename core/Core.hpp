#ifndef _CORE_H_
# define _CORE_H_

#include <vector>
#include <list>
#include "LibInt.hpp"

class               Core
{
private:

  std::vector< std::vector<int> > map_;
  // 0 - nothing                   ^
  // 1 - food                      ^
  // 3 - head                      ^
  // 2 - snake                     ^
  // 4 - tail                      ^

  std::list<grid>   s_;
  grid              sOn_;
  int               d_; // dir_ index
  std::vector<char> dir_; // direction
  bool              dLocked_; // direction lock
  grid              mapS_; // map size

  void              init(LibInt *gl); // init Core
  void              dirInit(); // init directions
  void              tryToGo();
  void              goOn(); // go snake go !
  bool              generF(); // food generator
  bool              sAlive() const; // snake status
  void              changeDir(char d); // change direction

public:
  Core();
  ~Core();

  int               start(LibInt *gl);
};

#endif // !_CORE_H_
