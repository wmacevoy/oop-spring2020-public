#pragma once

#include <iostream>
#include <string>

namespace hello {
  struct Greeter {
    const std::string name;
    
    Greeter(const std::string &_name = "World");
    void greet(std::ostream &out = std::cout) const;
  };
}
