#pragma once

#include "sequence.h"

#include <string>

class StringSequence : public Sequence
{
 private:
  const std::string &s;
  size_t offset;

 public:
  StringSequence(const std::string &s_);
  virtual int peek(unsigned delta=0);
  virtual size_t at();
  virtual void shift(unsigned delta=1);
};
