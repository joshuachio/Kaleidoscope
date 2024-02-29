#ifndef PrototypeAST_H
#define PrototypeAST_H

#include "global.h"

class PrototypeAST {
  std::string name;
  std::vector<std::string> args;

public:
  PrototypeAST(const std::string &name, std::vector<std::string> args) :
    name(name), args(std::move(args)) {};
};

#endif