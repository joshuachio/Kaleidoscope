#ifndef NumberExprASH_H
#define NumberExprASH_H

#include "ExprAST.h"

class NumberExprAST : public ExprAST {
private:
  double val;

public:
  NumberExprAST(double val) : val(val) {};

  void accept(ASTVisitor &visitor) override
  {
    visitor.visit(*this);
  }

};


#endif