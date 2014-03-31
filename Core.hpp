#ifndef _CORE_H_
# define _CORE_H_

#include <vector>
#include "IAssistant.hpp"

class               Core
{
protected:
private:
  std::vector< std::vector<int> >  map_;

  std::vector<grid> s_;
  char              dir_;
  grid              mapS_;

  void              init(IAssistant *gl);

public:
  Core();
  ~Core();

  void              start(IAssistant *gl);
};

#endif // !_CORE_H_
