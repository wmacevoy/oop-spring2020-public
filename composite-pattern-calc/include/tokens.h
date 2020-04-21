#pragma once

#include "sequence.h"
#include "token.h"

#include <list>
#include <memory>

class Tokens
{
 private:
  SequenceSP sequence;
  std::list < Token > ahead;
  void next();
 public:
  Tokens(SequenceSP &sequence);
  const Token &peek(unsigned delta=0);
  void shift(unsigned delta=1);
};

typedef std::shared_ptr < Tokens > TokensSP;
