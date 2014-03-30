#ifndef _PARSER_H_
# define _PARSER_H_

#include <string>
#include "IAssistant.hpp"

class Parser
{
protected:
private:
  IAssistant* gl;
  bool        isDigits(const std::string &str);
  int         str2int(const std::string &str);
  void        parse(std::string &lib);

public:
  Parser();
  ~Parser();

  IAssistant* graphInit(std::string X, std::string Y, std::string &lib);
};

#endif // !_PARSER_H_
