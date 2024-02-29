#ifndef BinaryExprAST_H
#define BinaryExprAST_H

#include "ExprAST.h"
#include "global.h"


class BinaryExprAST : public ExprAST {
  char op;
  std::unique_ptr<ExprAST> LHS, RHS;

public:
  BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS) : 
    op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {};

};



#endif