#ifndef _CORE_H_
# define _CORE_H_

#include <vector>
#include <list>
#include "IAssistant.hpp"

class               Core
{
private:

  std::vector< std::vector<uint> >  map_;
  // 1st element index is [1][1]     ^
  // 0 - nothing                     ^
  // 1 - food                        ^
  // 2 - snake                       ^

  std::list<grid>   s_; // snake
  grid				      f_; // food
  int               d_; // dir_ index
  std::vector<char> dir_; // direction
  bool              dLocked_; // direction lock
  int               sOn_; // snake head status
  grid              sWas_; // snake back last position
  grid              mapS_; // map size

  void              init(IAssistant *gl); // init Core
  void              dirInit(); // init directions
  void              goOn(); // go snake go !
  void              generF(); // food generator
  bool              sAlive(); // snake status
  void              changeDir(char d); // change direction

public:
  Core();
  ~Core();

  int               start(IAssistant *gl);
};

#endif // !_CORE_H_
