#include "GL.hpp"

#include <stdexcept>
#include <SFML/Window.hpp>

GL::GL() {}

GL::~GL() {}

grid    GL::getReso() const
{
  grid  it;

  it.x = desk_.width;
  it.y = desk_.height;
	return it;
}

void  GL::init()
{
  desk_ = sf::VideoMode::getDesktopMode();
  if (!desk_.isValid())
    throw std::runtime_error("getDesktopMode() fail");
  if (!head_.loadFromFile("./head.png"))
    throw std::runtime_error("head_.loadFromFile error");
  if (!tail_.loadFromFile("./tail.png"))
    throw std::runtime_error("tail_.loadFromFile error");
  if (!body_.loadFromFile("./body.png"))
    throw std::runtime_error("body_.loadFromFile error");
  if (!block_.loadFromFile("./block.png"))
    throw std::runtime_error("block_.loadFromFile error");
  if (!food_.loadFromFile("./food.png"))
    throw std::runtime_error("food_.loadFromFile error");
}

void  GL::updateSnake(const std::list<grid> &s, const grid &f)
{
  std::list<grid>::const_iterator it;

  tmp_.setTexture(food_);
  tmp_.setPosition((f.x -1) * 20, (f.y-1) * 20);
  win_.draw(tmp_);
  it = s.begin();
  tmp_.setTexture(head_);
  tmp_.setPosition((it->x -1) * 20, (it->y-1) * 20); // TODO
  win_.draw(tmp_);
  tmp_.setTexture(body_);
  ++it;
  while (it != s.end())
  {
    ++it;
    if (it == s.end())
      break;
    --it;
    tmp_.setPosition((it->x -1) * 20, (it->y -1) * 20);
    win_.draw(tmp_);
    ++it;
  }
  --it;
  tmp_.setTexture(tail_);
  tmp_.setPosition((it->x -1) * 20, (it->y -1) * 20);
  win_.draw(tmp_);
}

void          GL::updateMap()
{
  uint        x;
  uint        y;

  tmp_.setTexture(block_);
  for (y = 0; y != mapS_.y; ++y)
  {
    for (x = 0; x != mapS_.x; ++x)
    {
      tmp_.setPosition(x * 20, y * 20);
      win_.draw(tmp_);
    }
  }
}

void  GL::updateWin()
{
  win_.display();
  win_.clear();
}

void  GL::drawWa(const std::list<grid> &s, const grid &f)
{
  updateMap();
  updateSnake(s, f);
  updateWin();
}

void  GL::newWin(const std::list<grid> &s, const grid &f)
{
  std::list<grid>::const_iterator it;
  sf::VideoMode                   gWin;
  uint                            x;

  gWin = sf::VideoMode(mapS_.x * 20, mapS_.y * 20);
  win_.create(gWin, "Nibbler ~", sf::Style::Titlebar);
  updateMap();
  updateSnake(s, f);
  updateWin();
}

grid  GL::setMapS(const grid &mapS)
{
  mapS_ = mapS;
  winMaxS_ = grid((mapS.x * 20) + 35, (mapS.y * 20) + 35);
  return (winMaxS_);
}

bool  GL::eventOccured()
{
  if (win_.pollEvent(event_))
    return true;
  else
    return false;
}

bool  GL::escP()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  else
    return false;
}

bool  GL::anyR()
{
  if (eventOccured())
  {
    if (event_.type == sf::Event::KeyReleased)
      return true;
    else
      return false;
  }
  else
    return false;
}

bool  GL::leftP()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    return true;
  else
    return false;
}

bool  GL::rightP()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    return true;
  else
    return false;
}
