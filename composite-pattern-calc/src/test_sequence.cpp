#include "istreamsequence.h"
#include "stringsequence.h"

#include <math.h>
#include <string>
#include <sstream>
#include <assert.h>

using namespace std;

void test()
{
  for (int t=0; t<100; ++t) {

    // random letter string
    string s;
    int n = rand() % 100;
    for (int i=0; i<n; ++i) {
      s.push_back('a'+rand()%('z'-'a'+1));
    }

    istringstream is(s); // std::istream 
    IStreamSequence a(is);
    StringSequence b(s);
    
    for (int i=0; i<1000; ++i) {
      int delta = rand()%4;
      switch(rand() % 3) {
      case 0: assert(a.at() == b.at()); break;
      case 1: assert(a.peek(delta) == b.peek(delta)); break;
      case 2: a.shift(delta); b.shift(delta); break;
      }
    }
  }
}

int main()
{
  test();
  cout << "ok" << endl;
  return 0;
}


