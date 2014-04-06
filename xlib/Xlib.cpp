#include "Xlib.hpp"
#include <iostream>

Xlib::Xlib() {}

Xlib::~Xlib() {}

extern "C"
{
  LibInt* crValidLib()
  {
    return new Xlib();
  }
}

void	Xlib::init()
{
  dpy_ = XOpenDisplay(NULL);
  colormap_ = DefaultColormap(dpy_, 0);
  XAllocNamedColor(dpy_, colormap_, "yellow", &colors_[1], &colors_[1]);
  XAllocNamedColor(dpy_, colormap_, "green", &colors_[2], &colors_[2]);
}

grid	Xlib::getReso() const
{
  grid	it;
  it.x = DisplayWidth(dpy_, 0);
  it.y = DisplayHeight(dpy_, 0);
  return it;
}

grid	Xlib::setMapS(const grid &mapS)
{
  mapS_ = mapS;
  winMaxS_ = grid((mapS.x * 25) + 35, (mapS.y * 25) + 35);
  return (winMaxS_);
}

void	Xlib::newWin(const std::vector< std::vector<int> > &map)
{
  win_ = XCreateSimpleWindow(dpy_, RootWindow(dpy_, 0), 1, 1, winMaxS_.x, 
			     winMaxS_.y, 0, BlackPixel(dpy_, 0), 
			     BlackPixel(dpy_,0));
  XMapWindow(dpy_, win_);
  for (int i = 0; i < 3; i++)
    {
      gColor_ = XCreateGC(dpy_, win_, 0, 0);
      XSetForeground(dpy_, gColor_, BlackPixel(dpy_, 0));
    }
  XSelectInput(dpy_, win_, ExposureMask | KeyPressMask);
  int x; int y;

  for (y = 0; y != mapS_.y; ++y)
  {
    for (x = 0; x != mapS_.x; ++x)
    {
      if (map[y][x] == 2 || map[y][x] == 3 || map[y][x] == 4)
      {
        XSetForeground(dpy_, gColor_, colors_[2].pixel);
        drawSnake(x * 25, y * 25, 25, 25, gColor_);
      }
      if (map[y][x] == 1)
      {
        XSetForeground(dpy_, gColor_, colors_[1].pixel);
        drawFood(x * 25, y * 25, 25, 25, gColor_);
      }
    }
  }
  XFlush(dpy_);
}

void	Xlib::drawWa(const std::vector< std::vector<int> > &map)
{
  XClearWindow(dpy_, win_);
  int x; int y;

  for (y = 0; y != mapS_.y; ++y)
  {
    for (x = 0; x != mapS_.x; ++x)
    {
      if (map[y][x] == 2 || map[y][x] == 3 || map[y][x] == 4)
      {
        XSetForeground(dpy_, gColor_, colors_[2].pixel);
        drawSnake(x * 25, y * 25, 25, 25, gColor_);
      }
      if (map[y][x] == 1)
      {
        XSetForeground(dpy_, gColor_, colors_[1].pixel);
        drawFood(x * 25, y * 25, 25, 25, gColor_);
      }
    }
  }
  XFlush(dpy_);
}

bool	Xlib::leftP()
{
  if (XLookupKeysym(&event_.xkey, 0) == XK_Left)
    {
      std::cout << "leftP" << std::endl;
      return true;
    }
  return false;
}

bool	Xlib::rightP()
{
  if (XLookupKeysym(&event_.xkey, 0) == XK_Right)
    {
      std::cout << "rightP" << std::endl;
      return true;
    }
  return false;
}

bool	Xlib::escP()
{
  XNextEvent(dpy_, &event_);
  if (XLookupKeysym(&event_.xkey, 0) == XK_Escape)
    {
      return true;
    }
  return false;
}

bool	Xlib::anyR()
{
  XNextEvent(dpy_, &event_);
  if (event_.type == KeyPress)
    return true;
  return false;
}

void  Xlib::drawSnake(int x1, int y1, int x2, int y2, GC color)
{
  XFillRectangle(dpy_, win_, color, x1, y1, x2, y2);
}

void  Xlib::drawFood(int x1, int y1, int x2, int y2, GC color)
{
  XDrawRectangle(dpy_, win_, color, x1, y1, x2, y2);
}

bool  Xlib::xPressed()
{
  return false;
}

bool  Xlib::anyP()
{
  XNextEvent(dpy_, &event_);
  if (event_.type == KeyPress)
    return true;
  return false;
}
