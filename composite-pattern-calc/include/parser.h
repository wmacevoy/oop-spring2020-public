#pragma once

#include "ast.h"
#include "tokens.h"

class Parser
{
 public:
  class Syntax {  
  public: 
    std::string error;
    size_t at;
    Syntax(const std::string &error_, size_t at_);
    void print(std::ostream &out) const;
  };
  virtual ASTNodeSP parse(TokensSP &tokens)=0;
  virtual ~Parser();
};

typedef std::shared_ptr < Parser > ParserSP;

ParserSP CreateRecursiveDescentParser();

/*

  expression --> LPAREN expression OP expression RPAREN | NUMBER
  op --> TIMES | PLUS

 */
