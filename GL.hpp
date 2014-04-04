#ifndef _GL_H_
# define _GL_H_

#include <SFML/Graphics.hpp>
#include "Tools.hpp"
#include "IAssistant.hpp"


class               GL : public IAssistant
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

  void              updateMap();
  void              updateWin();
  void              updateSnake(const std::list<grid> &s, const grid &f);

public:
  GL();
  virtual ~GL();

  virtual grid      setMapS(const grid &mapS);
  virtual void      init();
	virtual grid      getReso() const;
  virtual void      newWin(const std::list<grid> &s, const grid &f);
  virtual void      drawWa(const std::list<grid> &s, const grid &f);
  virtual bool      eventOccured();
  virtual bool      escP();
  virtual bool      anyR();
  virtual bool      leftP();
  virtual bool      rightP();
};

#endif // !_GL_H_
