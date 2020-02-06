#include "Greeter.h"

namespace hello {
  Greeter::Greeter(const std::string &_name) 
    : name(_name) // initialize name
  {

  }

  void Greeter::greet(std::ostream &out) const
  {
    out << "Hello, " << name << "!" << std::endl;
  }
}
