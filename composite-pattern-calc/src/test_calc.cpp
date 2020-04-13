#include "ast.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <assert.h>
#include <math.h>

#include "calc.h"
using namespace std;

ASTNodeSP randASTNodeSP(int d);
ASTNode* randASTNodeP(int d);

ASTNode* randASTNodeP(int d)
{
  if (d <= 0 || (rand() % 10 < 2)) {
    if (rand() % 2 == 0) {
      if (rand() %4 == 0) {
	return new ASTNumber(rand()%1000);
      } else {
	return new ASTNumber(rand()%10);
      }
      
    } else {
      std::string name;
      name.push_back('a'+(rand()%('z'-'a'+1)));
      return new ASTSymbol(name);
    }
  } else {
    if (rand() % 2 == 0) {
      return new ASTSum(randASTNodeSP(d-1),randASTNodeSP(d-1));
    } else {
      return new ASTProduct(randASTNodeSP(d-1),randASTNodeSP(d-1));
    }
  }
}

ASTNodeSP randASTNodeSP(int d)
{
  return ASTNodeSP(randASTNodeP(d));
}

ASTNodeSP randProgram(int d)
{
  ASTStatements *statements = new ASTStatements();
  int n = rand() % d + 5;
  for (int i=0; i<n; ++i) {
    statements->statements.push_back(randASTNodeSP(d));
  }
  return ASTNodeSP(statements);
}

void save_test(int d,string file)
{
}

void run_test(string file)
{
}

void test()
{
  for (int i=0; i<10; ++i) {
    ostringstream oss;
    oss << "tmp/test" << i << ".wmpp";
    string file=oss.str();

    {
      ofstream out(file.c_str());
      randProgram(2*i+1)->print(out);
    }

    {
      Calc calc;
      cout << calc.evalf(file) << endl;
    }
  }
}

int main()
{
  test();
  cout << "ok" << endl;
  return 0;
}
