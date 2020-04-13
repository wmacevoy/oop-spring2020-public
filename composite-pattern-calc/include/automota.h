#pragma once

#include <map>
#include <set>
#include <list>
#include <iostream>
#include "sequence.h"

class Automota
{
 public:
  // this maps (state,code) pairs into a set of new states.
  typedef std::map < std::pair < int , int > , std::set <int> > Transitions;
  Transitions transitions;

  // the set of states considered to be accepting of the input
  typedef std::set < int > Accepting;
  Accepting accepting;

  // the current set of states considered to be active in the automota
  typedef std::set < int > Active;
  Active active;

  void start();    
  void transition(int code);
  bool accepted() const;
  bool halted() const;

  int shortestPrefix(Sequence &s, std::list < int > *match=0);
  int longestPrefix(Sequence &s, std::list < int > *match=0);
  bool accepts(Sequence &s);

  std::set<int> states() const;

  void print(std::ostream &out) const;
  void print() const;

  // create an automota that matches only the empty string
  static Automota match();

  // create an automota that matches only the given code
  static Automota match(int code);

  // create an automota that matches a followed by b (ab)
  static Automota follows(const Automota &a, const Automota &b);

  // create an automota that matches either a or b (a|b).
  static Automota either(const Automota &a, const Automota &b);

  // create an automota that matches zero or more a's (a*)
  static Automota star(const Automota &a);
};

