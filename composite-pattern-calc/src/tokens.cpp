#include "token.h"
#include "tokens.h"
#include <string>

using namespace std;

Tokens::Tokens(SequenceSP &sequence_) 
  : sequence(sequence_)
{
}

void Tokens::next()
{
  int p = sequence->peek();
  string value;
  value.push_back(p);
  Token t(p,value,sequence->at());

  sequence->shift();

  if ('0' <= p && p <= '9') {
    t.type = Token::T_NUMBER;
    for (;;) {
      int check = sequence->peek();
      if (check < '0'  || check > '9') break;
      t.value.push_back(sequence->peek());
      sequence->shift();
    }
  } else if ('a' <= p && p <= 'z') {
    t.type = Token::T_SYMBOL;
  } else {
    switch(p) {
    case '(': 
      t.type = Token::T_LPAREN;
      break;
    case ')': 
      t.type = Token::T_RPAREN;
      break;
    case '*': 
      t.type = Token::T_TIMES;
      break;
    case '+': 
      t.type = Token::T_PLUS;
      break;
    case '\n':
      t.type = Token::T_EOL;
      t.value = "";
      break;
    case '\r':
      if (sequence->peek() == '\n') sequence->shift();
      t.type = Token::T_EOL;
      t.value = "";
      break;
    case -1: 
      t.type = Token::T_END;
      t.value = "";
      break;
    default:
      t.type = Token::T_ERROR;
    }
  }
  ahead.push_back(t);
}

const Token& Tokens::peek(unsigned delta)
{
  while (ahead.size() <= delta) {
    next();
  }

  std::list < Token > :: iterator  i = ahead.begin();
  while (delta > 0) { ++i; --delta; }
  return *i;
}

void Tokens::shift(unsigned delta)
{
  while (ahead.size() < delta) {
    next();
  }
  while (delta > 0) {
    ahead.pop_front();
    --delta;
  }
}
