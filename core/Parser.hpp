#ifndef _PARSER_H_
# define _PARSER_H_

#include <string>
#include "LibInt.hpp"

class     Parser
{
private:
  LibInt  *gl;
  void    *dlhandle;
  bool    isDigits(const std::string &str) const;
  int     str2int(const std::string &str) const;
  void    parse(std::string &str);
  int     parsePath(std::string &lib) const;

public:
          Parser();
          ~Parser();

  LibInt* graphInit(const std::string &X, const std::string &Y, 
                        std::string &lib);
};

#endif // !_PARSER_H_
