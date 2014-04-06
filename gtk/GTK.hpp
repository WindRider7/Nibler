#ifndef _GTK_H_
# define _GTK_H_

#include <gtk/gtk.h>
#include <pthread.h>
#include "Tools.hpp"
#include "LibInt.hpp"

class               GTK : public LibInt
{
private:
  grid              winMaxS_; // window max size
  GtkWidget         *win_;
  pthread_t         gtk_; // main loop

  void              updateMap(const std::vector< std::vector<int> > &map);
  void              updateWin();

public:
  GTK();
  virtual ~GTK();

  virtual grid      setMapS(const grid &mapS);
  virtual void      init();
  virtual grid      getReso() const;
  virtual void      newWin(const std::vector< std::vector<int> > &map);
  virtual void      drawWa(const std::vector< std::vector<int> > &map);
  virtual bool      escP();
  virtual bool      anyR();
  virtual bool      anyP();
  virtual bool      leftP();
  virtual bool      rightP();
  virtual bool      xPressed();
  virtual bool      eventOccured();
};

#endif // !_GTK_H_
