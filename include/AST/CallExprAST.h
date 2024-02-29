#ifndef CallExprAST_H
#define CallExprAST_H

#include "ExprAST.h"
#include "global.h"

class CallExprAST : public ExprAST {
  std::string callee;
  std::vector<std::unique_ptr<ExprAST>> args;

public:
  CallExprAST(const std::string &callee, std::vector<std::unique_ptr<ExprAST>> args) :
    callee(callee), args(std::move(args)) {};
};

#endif