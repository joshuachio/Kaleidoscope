#ifndef FunctionAST_H
#define FunctionAST_H

#include "global.h"
#include "codegen/ASTVisitor.h"

class FunctionAST {
  std::unique_ptr<PrototypeAST> proto;
  std::unique_ptr<ExprAST> body;

public:
  FunctionAST(std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprAST> body) :
    proto(std::move(proto)), body(std::move(body)) {};

  void accept(ASTVisitor &visitor)
  {
    visitor.visit(*this);
  }
};

#endif