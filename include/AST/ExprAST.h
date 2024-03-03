#ifndef ExprAST_H
#define ExprAST_H

#include "codegen/ASTVisitor.h"
// class ASTVisitor;


class ExprAST {

public:
  virtual ~ExprAST() = default;
  virtual void accept( ASTVisitor & ) = 0;
};


#endif