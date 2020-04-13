#include <iostream>
#include "calc.h"

using namespace std;

int main(int argc, char *argv[])
{
  Calc calc;
  for (int argi=1; argi<argc; ++argi) {
    string arg=argv[argi];
    try {
      double ans=calc.eval(arg);
      cout << arg << "=" << ans << endl;
    } catch (Parser::Syntax &e) {
      cout << "'" << arg << "' failed: " << e.error << "." << endl;
    }
  }
  return 0;
}
