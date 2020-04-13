#include "parser.h"

#include <sstream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

Parser::Syntax::Syntax(const std::string &error_, size_t at_) 
  : error(error_), at(at_) 
{
  // empty
}

void Parser::Syntax::print(std::ostream &out) const
{
  out << "error at " << at << ": " << error << endl;
}

Parser::~Parser() {}

// start := statements
// statements := statement statements | EOF
// statement := expression EOL
// expression := LPAREN expression op expression RPAREN | literal
// op := TIMES | PLUS
// literal := NUMBER | SYMBOL

class RecursiveDescentParser : public Parser
{
private:
  TokensSP tokens;

  const Token& peek(unsigned delta=0) { return tokens->peek(delta); }
  void shift(unsigned delta=1) { tokens->shift(delta); }
  size_t at() { return peek().at; }

  void syntax()
  {
    std::ostringstream message;
    message << "syntax error at offset " << at() << " near " << peek() << endl;
    throw Parser::Syntax(message.str(),at());
  }

  TokenSP match(int type)
  {
    if (peek().type  == type) {
      TokenSP ans(new Token(peek()));
      shift();
      return ans;
    } else {
      return TokenSP();
    }
  }

  bool end()
  {
    return match(Token::T_END)!=TokenSP();
  }

  bool eol()
  {
    return match(Token::T_EOL)!=TokenSP();
  }


  bool lparen()
  {
    return match(Token::T_LPAREN) != TokenSP();
  }

  bool rparen()
  {
    return match(Token::T_RPAREN) != TokenSP();
  }

  bool op(int &type)
  {
    const Token &t = peek();
    
    if (t.type == Token::T_PLUS || t.type == Token::T_TIMES) {
      type = t.type;
      shift();
      return true;
    } else {
      return false;
    }
  }

  bool number(ASTNodeSP &n)
  {
    TokenSP t=match(Token::T_NUMBER);
    if (t) {
      n = ASTNodeSP(new ASTNumber(atoi(t->value.c_str())));
    } else {
      n = ASTNodeSP();
    }
    return n != ASTNodeSP();
  }

  bool symbol(ASTNodeSP &x)
  {
    TokenSP t=match(Token::T_SYMBOL);
    if (t) {
      x = ASTNodeSP(new ASTSymbol(t->value));
    } else {
      x = ASTNodeSP();
    }
    return x != ASTNodeSP();
  }

  bool literal(ASTNodeSP &as)
  {
    return number(as) || symbol(as);
  }

  bool expression(ASTNodeSP &e)
  {
    if (peek().type == Token::T_LPAREN) {
      ASTNodeSP lhs;
      int optype;
      ASTNodeSP rhs;
      if (lparen() && expression(lhs) && op(optype) && expression(rhs) && rparen()) {
	if (optype == Token::T_PLUS) {
	  e=ASTNodeSP(new ASTSum(lhs,rhs));
	} else if (optype == Token::T_TIMES) {
	  e=ASTNodeSP(new ASTProduct(lhs,rhs));
	} else {
	  assert(false);
	}
	return true;
      } else {
	syntax(); 
      }
    } else {
      return literal(e);
    }
    return false;
  }

  bool statement(ASTNodeSP &e)
  {
    return expression(e) && eol();
  }

  bool statements(ASTNodeSP &e)
  {
    if (end()) {
      e = ASTNodeSP(new ASTStatements());
      return true;
    } 
    ASTNodeSP s;
    if (statement(s) && statements(e)) {
      ((ASTStatements&)(*e)).statements.push_front(s);
      return true;
    }
    syntax();
    return false;
  }
  
public:
  // start -> expression EOF
  ASTNodeSP parse(TokensSP &tokens_)
  {
    tokens=tokens_;
    ASTNodeSP e;
    if (statements(e)) {
      return e;
    } else {
      syntax();
    }
    return ASTNodeSP();
  }
};

ParserSP CreateRecursiveDescentParser() 
{
  return ParserSP(new RecursiveDescentParser());
}
