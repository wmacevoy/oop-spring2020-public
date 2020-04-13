#include "token.h"
#include <iostream>

Token::Token(int type_, const std::string &value_, size_t at_)
  : type(type_), value(value_), at(at_)
{

}

bool operator==(const Token &a, const Token &b)
{
  return a.type == b.type && a.value == b.value && a.at == b.at;
}

void Token::print(std::ostream &out) const
{
  if (type == T_END) {
    out << "eof";
  } else if (type == T_NUMBER) {
    out << "#" << value;
  } else {
    out << (char) type;
  }
}

std::ostream& operator<<(std::ostream &out, const Token &token)
{
  token.print(out);
  return out;
}


