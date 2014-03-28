#include <iostream> // I/O
#include <stdexcept> // logic_error, runtime_error
#include <exception> // exception
#include <cstdlib> // EXIT_
#include <sstream> // stringstream
#include <string> // string
#include "IAssistant.hpp"

void  myExit(int s)
{
  std::cout << "Exit" << std::endl;
  if (s == 0)
    exit(EXIT_SUCCESS);
  else
    exit(EXIT_FAILURE);
}

bool  isDigits(const std::string &str)
{
  return str.find_first_not_of("0123456789") == std::string::npos;
}

int                 str2int(const std::string &str)
{
  std::stringstream ss(str);
  int               num;

  if ((ss >> num).fail())
    throw std::runtime_error("'str2int' error");
  return num;
}

IAssistant    *parse(std::string &lib)
{
  std::string it;
  GL          *real;

  it.append("'").append(lib).append("' is not a library");
  if ((lib.compare(0, 12, "lib_nibbler_") != 0)
    || (lib.compare((lib.size() - 3), 3, ".so") != 0))
    throw std::logic_error(it);
  real = new GL;// I will use external_creator(); instead
  return real; //     ^
}

void          start(std::string X, std::string Y, std::string lib)
{
  IAssistant  *gl;
  grid        curr;

  try
  {
    gl = parse(lib);
    std::cout << "Initializing graphics ..." << std::flush;
    gl->init(); std::cout << " Done" << std::endl;
    if (!isDigits(X) || !isDigits(Y))
      throw std::logic_error("Invalid value passed");
    curr.x = str2int(X);
    curr.y = str2int(Y);
    if (gl->getReso().x < curr.x || gl->getReso().y < curr.y)
      throw std::logic_error("Game area is too big");
    if (7 > curr.x || 7 > curr.y)
      throw std::logic_error("Game area is too small");

    delete [] gl;
  }
  catch (std::logic_error &error)
  {
    delete [] gl;
    std::cout << "Error: " << error.what() << std::endl
              << "Use: './nibbler --help' for more info" << std::endl;
    myExit(0);
  }
  catch (std::exception &error)
  {
    delete [] gl;
    std::cerr << "Error: " << error.what() << std::endl;
    myExit(1);
  }
}

int           main(int argc, char const *argv[])
{
  std::string helpArg = "--help";

  if (argc == 2)
  {
    if (helpArg.compare(argv[1]) == 0)
    {
      std::cout << "Usage: './nibbler X Y lib_nibbler_***.so'" << std::endl
                << "Where : " << std::endl
                << "'***' is the name of the GL" << std::endl
                << "X - game area width" << std::endl
                << "Y - game area height" << std::endl
                << "Game area cannot exceed screen resolution" << std::endl
                << "X cannot be less then 7px" << std::endl
                << "Y cannot be less then 7px" << std::endl;
    }
    std::cout << "Exiting" << std::endl;
    myExit(0);
  }
  if (argc != 4)
  {
    std::cout << "Invalid number of arguments" << std::endl
              << "Use: './nibbler --help' for info" << std::endl;
    myExit(0);
  }
  start(argv[1], argv[2], argv[3]); // lvl down
	myExit(0);
}