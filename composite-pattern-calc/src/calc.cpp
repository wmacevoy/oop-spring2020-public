#include "calc.h"
#include "parser.h"
#include "stringsequence.h"
#include "istreamsequence.h"
#include "tokens.h"
#include <fstream>

double Calc::eval(const std::string &expression)
{
  if (!parser) {
    parser = CreateRecursiveDescentParser();
  }
  SequenceSP sequence(new StringSequence(expression));
  TokensSP tokens(new Tokens(sequence));
  return parser->parse(tokens)->eval();
}

double Calc::evalf(const std::string &filename)
{
  if (!parser) {
    parser = CreateRecursiveDescentParser();
  }
  std::ifstream file(filename.c_str());
  SequenceSP sequence(new IStreamSequence(file));
  TokensSP tokens(new Tokens(sequence));
  return parser->parse(tokens)->eval();
}
