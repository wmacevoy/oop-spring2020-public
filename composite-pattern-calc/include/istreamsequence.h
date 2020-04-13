#pragma once

#include "sequence.h"

#include <iostream>
#include <list>

class IStreamSequence : public Sequence
{
 private:
  std::istream &is;
  std::list<int> ahead;
  size_t offset;
 public:
  IStreamSequence(std::istream &is_);
  virtual int peek(unsigned delta=0);
  virtual size_t at();
  virtual void shift(unsigned delta=1);
};
