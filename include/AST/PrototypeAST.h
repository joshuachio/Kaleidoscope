#ifndef PrototypeAST_H
#define PrototypeAST_H

#include "global.h"
#include "codegen/ASTVisitor.h"

class PrototypeAST {
  std::string name;
  std::vector<std::string> args;

public:
  PrototypeAST(const std::string &name, std::vector<std::string> args) :
    name(name), args(std::move(args)) {};

  void accept(ASTVisitor &visitor)
  {
    visitor.visit(*this);
  }
};

#endif