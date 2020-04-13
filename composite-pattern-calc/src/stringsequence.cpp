#include "stringsequence.h"

StringSequence::StringSequence(const std::string &s_) 
  :  s(s_), offset(0)
{
}

int StringSequence::peek(unsigned delta)
{
  return (offset + delta < s.length()) ? s[offset+delta] : -1;
}

size_t StringSequence::at() { 
  return offset;
}

void StringSequence::shift(unsigned delta)
{
  offset += delta;
}
