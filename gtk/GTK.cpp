#include "GTK.hpp"

#include <stdexcept> // runtime_error

extern "C"
{
  LibInt* crValidLib()
  {
    return new GTK();
  }
}

// private memory:

int   g_xB; // (x) button

// End ^

// private functions:

static void destroy(GtkWidget *widget, gpointer data)
{
  (void)widget;
  (void)data;
  g_xB = 1;
  gtk_main_quit();
}

static void key_pressed(GtkWidget *widget, gpointer data)
{
  (void)widget;
  (void)data;
}

void *start(void *arg)
{
  (void)arg;
  gtk_main();
  return (NULL);
}

// End ^

GTK::GTK() {}

GTK::~GTK() {}

grid    GTK::getReso() const
{
  grid  it;

  it.x = 1920;
  it.y = 1080;
  return it;
}

void    GTK::init()
{
  g_xB = 0;
  gtk_init(0, NULL);
  win_ = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request(win_, mapS_.x * 30, mapS_.y * 30);
  gtk_window_set_resizable (GTK_WINDOW(win_), FALSE);
  g_signal_connect(win_, "destroy", G_CALLBACK(destroy), NULL);
  g_signal_connect (win_, "key_press_event", G_CALLBACK (key_pressed), NULL);
  std::cout << "GTK: I AM NOT READY YET x(" << std::endl;
}

void  GTK::updateMap(const std::vector< std::vector<int> > &map)
{
  int x;
  int y;
  
  (void)map;
  for (y = 0; y != mapS_.y; ++y) // update map
  {
    for (x = 0; x != mapS_.x; ++x)
    {
    
    }
  }
}

void  GTK::updateWin()
{

}

void  GTK::drawWa(const std::vector< std::vector<int> > &map)
{
  int x;
  int y;

  (void)map;
  for (y = 0; y != mapS_.y; ++y)
  {
    for (x = 0; x != mapS_.x; ++x)
    {
      
    }
  }
}

void  GTK::newWin(const std::vector< std::vector<int> > &map)
{
  (void)map;
  gtk_widget_show(win_);
  pthread_create(&gtk_, NULL, start, NULL);
}

grid  GTK::setMapS(const grid &mapS)
{
  mapS_ = mapS;
  winMaxS_ = grid((mapS.x * 30) + 35, (mapS.y * 30) + 35);
  return (winMaxS_);
}

bool  GTK::eventOccured()
{
  return true;
}

bool    GTK::escP()
{
  return false;
}

bool  GTK::anyR()
{
  return true;
}

bool  GTK::anyP()
{
  return true;
}

bool  GTK::xPressed()
{
  if (g_xB == 1)
    return true;
  else
    return false;
}

bool  GTK::leftP()
{
  return false;
}

bool  GTK::rightP()
{
  return false;
}
