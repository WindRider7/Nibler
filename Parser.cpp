#include "Parser.hpp"

#include <sstream> // stringstream
#include <stdexcept> // logic_error, runtime_error
#include "Tools.hpp"
#include "GL.hpp" // NO

Parser::Parser() {}

Parser::~Parser() {}

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
  if (lib.compare((lib.size() - 3), 3, ".so") != 0)
    throw std::logic_error(it);
  it.replace(it.size() - 7, 15, "correct library");
  if (lib.compare(0, 12, "lib_nibbler_") != 0)
    throw std::logic_error(it);
  this->gl = new GL;// I will use external_creator(); instead
}

IAssistant*   Parser::graphInit(std::string X, std::string Y, std::string &lib)
{
  grid        reso;
  grid        mapS;
  grid        area;

  std::cout << "Initializing graphics ..." << std::endl;
  parse(lib);
  if (!isDigits(X) || !isDigits(Y))
    throw std::logic_error("Invalid value passed");
  mapS.x = str2int(X);
  mapS.y = str2int(Y);
  area = gl->setMapS(mapS);
  gl->init();
  reso = gl->getReso();
  if (reso.x < area.x || reso.y < area.y)
    throw std::logic_error("Game area is too big");
  if (mapS.x < 9 || mapS.y < 9)
    throw std::logic_error("Game area is too small");
  std::cout << " > Done" << std::endl;
  return this->gl;
}
