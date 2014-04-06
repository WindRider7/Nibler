#include "Parser.hpp"

#include <dlfcn.h> // dlopen, dlclose, dlsym
#include <sstream> // stringstream
#include <stdexcept> // logic_error, runtime_error
#include <exception>
#include "Tools.hpp"

Parser::Parser() {}

Parser::~Parser() 
{
  dlclose(dlhandle);
}

bool  Parser::isDigits(const std::string &str) const
{
  return str.find_first_not_of("0123456789") == std::string::npos;
}

int                 Parser::str2int(const std::string &str) const
{
  std::stringstream ss(str);
  int               num;

  if ((ss >> num).fail())
    throw std::runtime_error("'str2int' error");
  return num;
}

int   Parser::parsePath(std::string &lib) const
{
  int size = lib.size();
  int i = 0;

  while (i != size)
  {
    if (lib[i] == '/')
      return i + 1;
    ++i;
  }
  lib.insert(0, "./");
  return 2;
}

void          Parser::parse(std::string &lib)
{
  std::string str;
  LibInt*     (*extCreator)();
  int         r;


  r = parsePath(lib);
  str.append("'").append(lib).append("' is not a library");
  if (lib.compare((lib.size() - 3), 3, ".so") != 0)
    throw std::logic_error(str);
  str.replace(str.size() - 7, 15, "correct library");
  if (lib.compare(r, 12, "lib_nibbler_") != 0)
    throw std::logic_error(str);
  str.replace(str.size() - 15, 18, "compatible library");
  dlhandle = dlopen(lib.c_str(), RTLD_LAZY);
  if (dlhandle == NULL)
    throw std::runtime_error("fail while opening library");
  extCreator = reinterpret_cast<LibInt* (*)()>
              (dlsym(dlhandle, "crValidLib"));
  if (extCreator == NULL)
    throw std::runtime_error(str);
  gl = extCreator();
}

LibInt* Parser::graphInit(const std::string &X, const std::string &Y, 
                                std::string &lib)
{
  grid  reso;
  grid  mapS;
  grid  area;

try
{
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
catch (const std::logic_error &error)
{
  dlclose(dlhandle);
  throw;
}
catch (const std::runtime_error &error)
{
  dlclose(dlhandle);
  throw;
}
catch (...)
{
  dlclose(dlhandle);
  throw;
}

}
