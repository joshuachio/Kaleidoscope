#ifndef FunctionAST_H
#define FunctionAST_H

#include "ExprAST.h"
#include "PrototypeAST.h"
#include "global.h"

class FunctionAST {
  std::unique_ptr<PrototypeAST> proto;
  std::unique_ptr<ExprAST> body;

public:
  FunctionAST(std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprAST> body) :
    proto(std::move(proto)), body(std::move(body)) {};
};

#endif