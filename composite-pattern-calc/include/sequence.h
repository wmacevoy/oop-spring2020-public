#pragma once

#include "stddef.h"
#include <memory>

class Sequence
{
 public:
  virtual int peek(unsigned delta=0)=0;
  virtual size_t at()=0;
  virtual void shift(unsigned delta=1)=0;
  virtual ~Sequence();
};

typedef std::shared_ptr < Sequence > SequenceSP;
