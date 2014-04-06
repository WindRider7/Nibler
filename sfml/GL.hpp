#ifndef _GL_H_
# define _GL_H_

#include <SFML/Graphics.hpp> //graphics module
#include "Tools.hpp"
#include "LibInt.hpp"


class               GL : public LibInt
{
private:
  grid              winMaxS_; // window max size
  sf::VideoMode     desk_; // desktop mode
  sf::Texture       head_;
  sf::Event         event_;
  sf::Texture       tail_;
  sf::Texture       body_;
  sf::Texture       food_;
  sf::Texture       block_;
  sf::RenderWindow  win_;
  sf::Sprite        tmp_;
  sf::Window        App_;

  void              updateMap(const std::vector< std::vector<int> > &map);
  void              updateWin();

public:
                    GL();
  virtual           ~GL();

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
  virtual bool      eventOccured();
};

#endif // !_GL_H_
