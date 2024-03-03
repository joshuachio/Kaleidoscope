#ifndef VariableExprAST_h
#define VariableExprAST_h

#include "ExprAST.h"
#include "global.h"

class VariableExprAST : public ExprAST {
  std::string name;

public:
  VariableExprAST(const std::string &name) : name(name) {};

  void accept(ASTVisitor &visitor) override
  {
    visitor.visit(*this);
  }

};

#endif