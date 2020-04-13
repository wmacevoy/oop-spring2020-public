#include "istreamsequence.h"

#include <iostream>

using namespace std;

IStreamSequence::IStreamSequence(std::istream &is_) 
  : is(is_)
{
  offset = 0;
}

size_t IStreamSequence::at() { 
  return offset-ahead.size();
}

int IStreamSequence::peek(unsigned delta)
{
  while (ahead.size() <= delta) {
    ahead.push_back(is.get());
    ++offset;
  }
  std::list < int > :: iterator  i = ahead.begin();
  while (delta > 0) { ++i; --delta; }
  return *i;
}

void IStreamSequence::shift(unsigned delta)
{
  while (ahead.size() < delta) {
    ahead.push_back(is.get());
    ++offset;
  }
  while (delta > 0) {
    ahead.pop_front();
    --delta;
  }
}
