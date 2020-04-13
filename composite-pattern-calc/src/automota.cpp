#include "automota.h"

using namespace std;

void Automota::start()
{
  active.clear();
  active.insert(0);
}

void Automota::transition(int code)
{
  Active active_;
  for (Active::iterator i = active.begin(); i != active.end(); ++i) {
    pair < int , int > key(*i,code);
    Transitions::iterator j = transitions.find(key);
    if (j != transitions.end()) {
      active_.insert(j->second.begin(),j->second.end());
    }
  }
  active.swap(active_);
}

bool Automota::accepted() const
{
  for (Active::const_iterator i = active.begin(); i != active.end(); ++i) {
    if (accepting.find(*i) != accepting.end()) return true;
  }
  return false;
}

bool Automota::halted() const
{
  return active.empty();
}

int Automota::shortestPrefix(Sequence &s, std::list < int > *match)
{
  if (match != 0) match->clear();
  int i=0;
  start();
  for (;;) {
    if (accepted()) return i;
    int c = s.peek(i);
    if (c == -1) break;
    if (match != 0) match->push_back(c);
    transition(c);
    if (halted()) break;
    ++i;
  }
  if (match != 0) match->clear();
  return -1;
}

int Automota::longestPrefix(Sequence &s, std::list < int > *match)
{
  int matched=-1,i=0;
  if (match != 0) match->clear();
  start();
  for (;;) {
    if (accepted()) matched = i;
    int c = s.peek(i);
    if (c == -1) break;
    if (match != 0) match->push_back(c);
    transition(c);
    if (halted()) break;
    ++i;
  }
  if (matched >= 0) {
    if (match != 0) {
      while (match->size() > matched) { match->pop_back(); }
    }
    return matched;
  } else {
    if (match != 0) match->clear();
    return -1;
  }
}

bool Automota::accepts(Sequence &s)
{
  start();
  while (s.peek() != -1) {
    transition(s.peek());
    if (halted()) return false;
    s.shift();
  }
  return accepted();
}

Automota Automota::match()
{
  Automota ans;
  ans.accepting.insert(0);
  return ans;
}

Automota Automota::match(int code)
{
  Automota ans;
  ans.accepting.insert(1);
  ans.transitions[pair<int,int>(0,code)].insert(1);
  return ans;
}

set<int> Automota::states() const
{
  set<int> ans;
  ans.insert(0);
  for (Transitions::const_iterator i=transitions.begin(); i != transitions.end(); ++i) {
    ans.insert(i->second.begin(),i->second.end());
  }
  return ans;
}

Automota Automota::follows(const Automota &a, const Automota &b)
{
  Automota ans;

  set<int> astates=a.states();
  set<int> bstates=b.states();
  
  map<int,int> a2join;
  map<int,int> b2join;

  int count=0;
  for (set<int>::iterator i=astates.begin(); i!=astates.end(); ++i) {
    a2join[*i]=count;
    ++count;
  }

  for (set<int>::iterator i=bstates.begin(); i!=bstates.end(); ++i) {
    if (*i == 0 && a.accepting.find(0) != a.accepting.end()) {
      b2join[*i]=0;
    } else {
      b2join[*i]=count;
      ++count;
    }
  }

  for (Transitions::const_iterator i=a.transitions.begin(); i != a.transitions.end(); ++i) {
    const pair<int,int> &key=i->first;
    int fromState = a2join[key.first];
    int code = key.second;
    set<int> toStates;
    for (set<int>::const_iterator p=i->second.begin(); p != i->second.end(); ++p) {
      if (a.accepting.find(*p) != a.accepting.end()) {
	toStates.insert(b2join[0]);
      }
      toStates.insert(a2join[*p]);
    }
    ans.transitions[pair<int,int>(fromState,code)]=toStates;
  }

  for (Transitions::const_iterator i=b.transitions.begin(); i != b.transitions.end(); ++i) {
    const pair<int,int> &key=i->first;
    int fromState = b2join[key.first];
    int code = key.second;
    set<int> toStates;
    for (set<int>::const_iterator p=i->second.begin(); p != i->second.end(); ++p) {
      toStates.insert(b2join[*p]);
    }
    ans.transitions[pair<int,int>(fromState,code)].insert(toStates.begin(),toStates.end());
  }

  for (Accepting::const_iterator i=b.accepting.begin(); i != b.accepting.end(); ++i) {
    ans.accepting.insert(b2join[*i]);
  }

  return ans;
}

Automota Automota::either(const Automota &a, const Automota &b)
{
  Automota ans;

  set<int> astates=a.states();
  set<int> bstates=b.states();
  
  map<int,int> a2join;
  map<int,int> b2join;

  int count=1;
  a2join[0]=0;
  b2join[0]=0;

  for (set<int>::iterator i=astates.begin(); i!=astates.end(); ++i) {
    if (*i != 0) {
      a2join[*i]=count;
      ++count;
    }
  }

  for (set<int>::iterator i=bstates.begin(); i!=bstates.end(); ++i) {
    if (*i != 0) {
      b2join[*i]=count;
      ++count;
    }
  }

  for (Transitions::const_iterator i=a.transitions.begin(); i != a.transitions.end(); ++i) {
    const pair<int,int> &key=i->first;
    int fromState = a2join[key.first];
    int code = key.second;
    set<int> toStates;
    for (set<int>::iterator p=i->second.begin(); p != i->second.end(); ++p) {
      toStates.insert(a2join[*p]);
    }

    ans.transitions[pair<int,int>(fromState,code)]=toStates;
  }

  for (Transitions::const_iterator i=b.transitions.begin(); i != b.transitions.end(); ++i) {
    const pair<int,int> &key=i->first;
    int fromState = b2join[key.first];
    int code = key.second;
    set<int> toStates;
    for (set<int>::iterator p=i->second.begin(); p != i->second.end(); ++p) {
      toStates.insert(b2join[*p]);
    }

    if (key.first != 0) {
      ans.transitions[pair<int,int>(fromState,code)]=toStates;
    } else {
      ans.transitions[pair<int,int>(fromState,code)].insert(toStates.begin(), toStates.end());
    }
  }

  for (Accepting::const_iterator i=a.accepting.begin(); i != a.accepting.end(); ++i) {
    ans.accepting.insert(a2join[*i]);
  }

  for (Accepting::const_iterator i=b.accepting.begin(); i != b.accepting.end(); ++i) {
    ans.accepting.insert(b2join[*i]);
  }

  return ans;
}

Automota Automota::star(const Automota &a)
{
  Automota ans(a);
  ans.accepting.insert(0);
  for (Transitions::iterator i=ans.transitions.begin(); i != ans.transitions.end(); ++i) {
    bool cycle = false;
    for (set<int>::iterator j=i->second.begin(); j!=i->second.end(); ++j) {
      if (a.accepting.find(*j) != a.accepting.end()) {
	cycle = true;
      }
    }
    if (cycle) {
      i->second.insert(0);
    }
  }
  return ans;
}

void Automota::print(std::ostream &out) const
{
  if (accepting.find(0) != accepting.end()) {
    out << "0 is an accepting state." << endl;
  } else {
    out << "0 is a non-accepting state." << endl;
  }
  for (Transitions::const_iterator i=transitions.begin(); i!=transitions.end(); ++i) {
    for (set<int>::const_iterator j=i->second.begin(); j != i->second.end(); ++j) {

      string fromStateName = "state";
      string toStateName = "state";

      if (accepting.find(i->first.first) != accepting.end()) {
	fromStateName = "accepting state";
      }

      if (accepting.find(*j) != accepting.end()) {
	toStateName = "accepting state";
      }

      out <<"at " << fromStateName << " " << i->first.first << ", getting " << i->first.second << " moves to " << toStateName << " " << *j << "." << endl;
      }
  }
}

void Automota::print() const 
{
  print(std::cout);
}

/* simple grammar for regular expressions...

re := terms;
terms := term optional_or;
optional_or := PIPE terms | ;
term := factor optional_term ;
optional_term := term | ;
factor := simple optional_factor ;
optional_factor := simple | ;
simple := atom optional_op;
optional_op := STAR | QUESTION | ;
atom := CHARACTER | LPAREN re RPAREN | ;

*/
