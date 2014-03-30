#include <iostream> // I/O
#include <exception> // exception
#include <cstdlib> // EXIT_
#include <stdexcept> // logic_error, runtime_error
#include <string> // string
#include "IAssistant.hpp"
#include "Parser.hpp"
#include "Core.hpp"

void  myExit(int s)
{
  std::cout << "Exit" << std::endl;
  if (s == 0)
    exit(EXIT_SUCCESS);
  else
    exit(EXIT_FAILURE);
}

void          start(std::string X, std::string Y, std::string lib)
{
  IAssistant  *gl;
  Parser      p;
  Core        c;

  try
  {
    gl = p.graphInit(X, Y, lib); // start
    c.start(gl); //                 lvl down
  }
  catch (std::logic_error &error)
  {
    delete gl;
    std::cout << "Error: " << error.what() << std::endl
              << "Use: './nibbler --help' for more info" << std::endl;
    myExit(0);
  }
  catch (std::exception &error)
  {
    delete gl;
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
