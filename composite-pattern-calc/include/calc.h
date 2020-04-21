#pragma once

#include <string>
#include "parser.h"

class Calc
{
 private:
  ParserSP parser;
 public:
  double eval(const std::string &expression);
  double evalf(const std::string &filename);
};
