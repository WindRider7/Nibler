#include <exception> // exception
#include <stdexcept> // logic_error, runtime_error
#include <string>
#include <iostream>
#include "LibInt.hpp"
#include "Parser.hpp"
#include "Core.hpp"

void          start(std::string X, std::string Y, std::string lib)
{
  LibInt      *gl = NULL;
  Parser      p;
  Core        c;

try
{
  gl = p.graphInit(X, Y, lib); // start
  c.start(gl); //                 lvl down / end
  delete gl;
}
catch (const std::logic_error &error)
{
  delete gl;
  std::cout << "Error: " << error.what() << std::endl
            << "Use: './nibbler --help' for more info" << std::endl;
  myExit(0);
}
catch (const std::exception &error)
{
  delete gl;
  std::cout << "Error: " << error.what() << std::endl;
  myExit(1);
}

}

int           main(int const argc, char const *argv[])
{
  std::string helpArg = "--help";

  if (argc > 2)
  {
    if (helpArg.compare(argv[1]) == 0)
    {
      std::cout << " > Usage: './nibbler X Y lib_nibbler_***.so'" << std::endl
                << "Where : " << std::endl
                << "'***' - name of the GL" << std::endl
                << "X - game area width" << std::endl
                << "Y - game area height" << std::endl
                << "Game Area cannot exceed screen resolution" << std::endl
                << "Game Area cannot be less then 9 x 9" << std::endl;
      myExit(0);
    }
  }
  if (argc != 4)
  {
    std::cout << "Invalid number of arguments" << std::endl
              << "Use: './nibbler --help' for info" << std::endl;
    myExit(0);
  }
  start(argv[1], argv[2], argv[3]); // start / lvl down
  myExit(0);
}
