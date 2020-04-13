#include "automota.h"
#include "sequence.h"
#include "stringsequence.h"

#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

void accept(Automota &a, const std::string &s)
{
  StringSequence ss(s);
  assert(a.accepts(ss) == true);
}

void reject(Automota &a, const std::string &s)
{
  StringSequence ss(s);
  assert(a.accepts(ss) == false);
}

void test()
{
  {
    Automota e=Automota::match();
    accept(e,"");
    reject(e,"a");
  }

  {
    Automota a=Automota::match('a');
    accept(a,"a");
    reject(a,"");
    reject(a,"b");
    reject(a,"aa");
    reject(a,"ab");
  }

  {
    Automota e=Automota::match();
    Automota a=Automota::match('a');
    Automota b=Automota::match('b');

    Automota ea=Automota::follows(e,a);
    Automota ab=Automota::follows(a,b);
    Automota ae=Automota::follows(a,e);

    accept(ea,"a");
    reject(ea,"");
    reject(ea,"b");
    reject(ea,"ab");

    accept(ab,"ab");
    reject(ab,"");
    reject(ab,"a");
    reject(ab,"b");
    reject(ab,"ba");
    reject(ab,"aba");
    reject(ab,"abab");
    reject(ab,"abb");
    reject(ab,"abba");
    
    accept(ae,"a");
    reject(ae,"");
    reject(ae,"b");
    reject(ae,"ab");
  }

  {
    Automota e=Automota::match();
    Automota a=Automota::match('a');
    Automota b=Automota::match('b');

    Automota e_a=Automota::either(e,a);
    Automota a_b=Automota::either(a,b);
    Automota a_e=Automota::either(a,e);

    accept(e_a,"");
    accept(e_a,"a");
    reject(e_a,"ab");
    reject(e_a,"aa");

    accept(a_b,"a");
    accept(a_b,"b");
    reject(a_b,"");
    reject(a_b,"ab");
    reject(a_b,"ba");
    reject(a_b,"aa");
    reject(a_b,"bb");
    
    accept(a_e,"");
    accept(a_e,"a");
    reject(a_e,"ab");
    reject(a_e,"aa");
  }

  {
    Automota e=Automota::match();
    Automota a=Automota::match('a');
    Automota b=Automota::match('b');

    Automota es=Automota::star(e);
    Automota as=Automota::star(a);
    Automota a_b=Automota::either(a,b);
    Automota ab=Automota::follows(a,b);
    Automota a_bs=Automota::star(a_b);
    Automota abs=Automota::star(ab);

    accept(es,"");
    reject(es,"a");
    reject(es,"b");

    accept(as,"");
    accept(as,"a");
    accept(as,"aa");
    reject(as,"b");
    reject(as,"ab");
    
    accept(a_bs,"");
    accept(a_bs,"a");
    accept(a_bs,"b");
    accept(a_bs,"aa");
    accept(a_bs,"ab");
    accept(a_bs,"ba");
    accept(a_bs,"bb");

    reject(a_bs,"x");
    reject(a_bs,"ax");
    reject(a_bs,"bx");
    reject(a_bs,"aax");
    reject(a_bs,"abx");
    reject(a_bs,"bax");
    reject(a_bs,"bbx");

    
    accept(abs,"");
    reject(abs,"a");
    reject(abs,"b");
    reject(abs,"aa");
    accept(abs,"ab");
    reject(abs,"ba");
    reject(abs,"bb");
    accept(abs,"abab");
    reject(abs,"aba");
    reject(abs,"abb");

    reject(abs,"x");
    reject(abs,"ax");
    reject(abs,"bx");
    reject(abs,"aax");
    reject(abs,"abx");
    reject(abs,"bax");
    reject(abs,"bbx");
  }

  {
    // a(a|b)*
    Automota a = Automota::follows(Automota::match('a'),Automota::star(Automota::either(Automota::match('a'),Automota::match('b'))));

    string s="abbababxxx";
    StringSequence ss(s);

    assert(a.shortestPrefix(ss) == 1);
    assert(a.longestPrefix(ss) == 7);
    assert(a.shortestPrefix(ss) == 1);
    assert(a.longestPrefix(ss) == 7);
  }
}

int main()
{
  test();
  cout << "ok" << endl;
  return 0;
}
