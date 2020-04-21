#pragma once

#include <stddef.h>
#include <string>
#include <memory>

class Token
{
 public:

  enum { T_END = -1, T_EOL='\n', T_LPAREN='(', T_RPAREN=')',
	 T_TIMES='*', T_PLUS='+', T_NUMBER='#', T_SYMBOL='x',
	 T_ERROR = '?' };
  int type; 
  std::string value;
  size_t at;
  void print(std::ostream &out) const;
  Token(int type_, const std::string &value_, size_t at_=0);
};

bool operator==(const Token &a, const Token &b);

typedef std::shared_ptr < Token > TokenSP;

std::ostream& operator<<(std::ostream &out, const Token &token);

