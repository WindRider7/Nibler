#ifndef _TIMER_H_
# define _TIMER_H_

#include <ctime> // clock_t, clock

class       Timer
{
private:
  clock_t   t_;
  clock_t   timeout_;

public:
  Timer();
  ~Timer();

  bool      isOut() const;
  void      reset(const clock_t &timeout);
};

#endif // !_TIMER_H_
