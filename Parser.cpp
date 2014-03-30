#include <sstream> // stringstream
#include <iostream> // I/O
#include <stdexcept> // logic_error, runtime_error
#include "Parser.hpp"

Parser::Parser()
{
  //ctor
}

Parser::~Parser()
{

}

bool  Parser::isDigits(const std::string &str)
{
  return str.find_first_not_of("0123456789") == std::string::npos;
}

int                 Parser::str2int(const std::string &str)
{
  std::stringstream ss(str);
  int               num;

  if ((ss >> num).fail())
    throw std::runtime_error("'str2int' error");
  return num;
}

void          Parser::parse(std::string &lib)
{
  std::string it;

  it.append("'").append(lib).append("' is not a library");
  if ((lib.compare(0, 12, "lib_nibbler_") != 0)
    || (lib.compare((lib.size() - 3), 3, ".so") != 0))
    throw std::logic_error(it);
  this->gl = new GL;// I will use external_creator(); instead   ^
}

IAssistant*   Parser::graphInit(std::string X, std::string Y, std::string &lib)
{
  grid        reso;
  grid        curr;

  parse(lib);
  std::cout << "Initializing graphics ..." << std::flush;
  gl->init(); std::cout << " Done" << std::endl;
  reso = gl->getReso();
  if (!isDigits(X) || !isDigits(Y))
    throw std::logic_error("Invalid value passed");
  curr.x = str2int(X);
  curr.y = str2int(Y);
  if (reso.x < curr.x || reso.y < curr.y)
    throw std::logic_error("Game area is too big");
  if (7 > curr.x || 7 > curr.y)
    throw std::logic_error("Game area is too small");
  gl->setArea(curr);
  return this->gl;
}
