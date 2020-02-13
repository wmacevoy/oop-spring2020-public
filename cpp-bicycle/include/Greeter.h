#pragma once

#include <iostream>
#include <string>

namespace hello {
  class Greeter {
    public: const std::string name;
    private: std::string greeting;
    
    public: Greeter(const std::string &_name = "World");
    public: void greet(std::ostream &out = std::cout) const;
    public: void setGreeting(const std::string &_greeting);
    public: const std::string & getGreeting() const;
  };
}
