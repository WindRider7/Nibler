#ifndef _XLIB_
# define _XLIB_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>

#include "LibInt.hpp"

class		Xlib : public LibInt
{
public:
  Xlib();
  virtual	~Xlib();

  virtual void	init();
  virtual grid	getReso() const;
  virtual grid	setMapS(const grid &mapS);

  virtual void	newWin(const std::vector< std::vector<int> > &map);
  virtual void	drawWa(const std::vector< std::vector<int> > &map);

  virtual bool	leftP();
  virtual bool	rightP();
  virtual bool	escP();
  virtual bool	anyR();
  virtual bool  anyP();
  virtual bool  xPressed();

private:
  grid		winMaxS_;
  Display	*dpy_;
  XEvent	event_;
  Window	win_;
  XColor	colors_[3];
  GC		gColor_;
  Colormap	colormap_;
  void    drawSnake(int x1, int y1, int x2, int y2, GC color);
  void    drawFood(int x1, int y1, int x2, int y2, GC color);
};

#endif // !_XLIB
