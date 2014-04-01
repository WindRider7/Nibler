#ifndef _CORE_H_
# define _CORE_H_

#include <vector>
#include <list>
#include "IAssistant.hpp"

class               Core
{
protected:
private:
  std::vector< std::vector<int> > map_;

  std::vector<grid> s_; // snake
  grid				      f_; // food
  char              dir_;
  grid              mapS_;

  void              init(IAssistant *gl);
  void              goOn();
  bool              sAlive();

public:
  Core();
  ~Core();

  int               start(IAssistant *gl);
};

#endif // !_CORE_H_
