#include "Timer.hpp"

Timer::Timer()
{
  this->t_ = clock();
  this->timeout_ = 0;
}

Timer::~Timer() {}

void  Timer::reset(const clock_t &timeout)
{
  this->t_ = clock();
  this->timeout_ = timeout;
}

bool  Timer::isOut() const
{
  if (clock() - this->t_ > this->timeout_)
    return true;
  else
    return false;
}
