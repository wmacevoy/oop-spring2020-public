#include "tokens.h"
#include "stringsequence.h"
#include <vector>
#include <iostream>
#include <assert.h>

typedef std::vector < Token > VTokens;

using namespace std;

VTokens vTokens;
string s;

int dist(const Token &a, const Token &b)
{
  int ans = 0;
  if (a.type != b.type) ans += 100;
  if (a.value != b.value) ans += 10;
  if (a.at != b.at) ans += 1;
  return ans;
}

void make_case()
{
  int n=rand()%100;
  s="";
  vTokens.clear();

  int state = 0;

  for (int i=0; i<n; ++i) {
    switch(rand() % 6) {
    case 0: 
      state=0;
      s.push_back('('); 
      vTokens.push_back(Token(Token::T_LPAREN,"("));
      break;
    case 1:
      state=0;
      s.push_back(')'); 
      vTokens.push_back(Token(Token::T_RPAREN,")"));
      break;
    case 2: 
      state=0;
      s.push_back('*'); 
      vTokens.push_back(Token(Token::T_TIMES,"*"));
      break;
    case 3: 
      state=0;
      s.push_back('+');
      vTokens.push_back(Token(Token::T_PLUS,"+"));
      break;
    case 4: 
      if (state == 0) {
	state = 1;
	string value;
	value.push_back('0' + (rand() % 10));
	s.append(value);
	vTokens.push_back(Token(Token::T_NUMBER,value));	  
      }
      break;
    case 5:
      state = 0;
      string value;
      value.push_back('a'+(rand()%('z'-'a'+1)));
      s.append(value);
      vTokens.push_back(Token(Token::T_ERROR,value));
      break;
    }
  }
}

void test_case()
{
  SequenceSP sequence(new StringSequence(s));
  Tokens tokens(sequence);
  Token end(Token::T_END,"");
  size_t offset=0;

  for (int i=0; i<1000; ++i) {
    int delta = rand()%4;
    switch(rand() % 2) {
    case 0: 
      {
	if (offset+delta < vTokens.size()) {
	  const Token &vt=vTokens[offset+delta];
	  assert(dist(tokens.peek(delta),vt) <= 1);
	} else {
	  assert(dist(tokens.peek(delta),end) <= 1);
	}
	break;
      case 1: 
	tokens.shift(delta); 
	offset += delta;
	break;
      }
    }
  }
}

void test() {
  for (int t=0; t<100; ++t) {
    make_case();
    test_case();
  }
}

int main()
{
  test();
  cout << "ok" << endl;
  return 0;
}
