#include "GL.hpp"

#include <stdexcept> // runtime_error
#include <SFML/Window.hpp> // window module

extern "C"
{
  LibInt* crValidLib()
  {
    return new GL();
  }
}

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
  if (!head_.loadFromFile("./sfml/head.png"))
    throw std::runtime_error("head_.loadFromFile fail");
  if (!tail_.loadFromFile("./sfml/tail.png"))
    throw std::runtime_error("tail_.loadFromFile fail");
  if (!body_.loadFromFile("./sfml/body.png"))
    throw std::runtime_error("body_.loadFromFile fail");
  if (!block_.loadFromFile("./sfml/block.png"))
    throw std::runtime_error("block_.loadFromFile fail");
  if (!food_.loadFromFile("./sfml/food.png"))
    throw std::runtime_error("food_.loadFromFile fail");
}

void  GL::updateMap(const std::vector< std::vector<int> >  &map)
{
  int x;
  int y;

  for (y = 0; y != mapS_.y; ++y) // update map
  {
    for (x = 0; x != mapS_.x; ++x)
    {
      tmp_.setTexture(block_);
      tmp_.setPosition(x * 20, y * 20);
      win_.draw(tmp_);
    }
  }
  for (y = 0; y != mapS_.y; ++y) // update objects
  {
    for (x = 0; x != mapS_.x; ++x)
    {
      if (map[y][x] == 1)
      {
        tmp_.setTexture(food_);
        tmp_.setPosition(x * 20, y * 20);
        win_.draw(tmp_);
      }
      if (map[y][x] == 2)
      {
        tmp_.setTexture(body_);
        tmp_.setPosition(x * 20, y * 20);
        win_.draw(tmp_);
      }
      if (map[y][x] == 3)
      {
        tmp_.setTexture(head_);
        tmp_.setPosition(x * 20, y * 20);
        win_.draw(tmp_);
      }
      if (map[y][x] == 4)
      {
        tmp_.setTexture(tail_);
        tmp_.setPosition(x * 20, y * 20);
        win_.draw(tmp_);
      }
    }
  }
}

void  GL::updateWin()
{
  win_.display();
  win_.clear();
}

void  GL::drawWa(const std::vector< std::vector<int> >  &map)
{
  updateMap(map);
  updateWin();
}

void  GL::newWin(const std::vector< std::vector<int> >  &map)
{
  std::list<grid>::const_iterator it;
  sf::VideoMode                   gWin;

  gWin = sf::VideoMode(mapS_.x * 20, mapS_.y * 20);
  win_.create(gWin, "Nibbler ~", sf::Style::Titlebar);
  updateMap(map);
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

bool  GL::anyP()
{
  if (eventOccured())
  {
    if (event_.type == sf::Event::KeyPressed)
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
