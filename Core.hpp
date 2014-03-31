#ifndef _CORE_H_
# define _CORE_H_

#include <vector>
#include "IAssistant.hpp"

class               Core
{
protected:
private:
  std::vector<grid> s_; // snake
  grid				      f_; // food
  char              dir_;
  grid              mapS_;

  void              init(IAssistant *gl);
  void              goOn();

public:
  Core();
  ~Core();

  void              start(IAssistant *gl);
};

#endif // !_CORE_H_
