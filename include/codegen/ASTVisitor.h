#ifndef ASTVISITOR_H
#define ASTVISITOR_H

// #include "../AST/BinaryExprAST.h"
// #include "../AST/CallExprAST.h"
// #include "../AST/FunctionAST.h"
// #include "../AST/NumberExprAST.h"
// #include "../AST/PrototypeAST.h"
// #include "../AST/VariableExprAST.h"
// #include "AST/ExprAST.h"

// class ExprAST;
class BinaryExprAST;
class CallExprAST;
class FunctionAST;
class NumberExprAST;
class PrototypeAST;
class VariableExprAST;

class ASTVisitor {

public:
  virtual ~ASTVisitor() {};

  virtual void visit( BinaryExprAST & ) = 0;
  virtual void visit( CallExprAST & ) = 0;
  virtual void visit( FunctionAST & ) = 0;
  virtual void visit( NumberExprAST & ) = 0;
  virtual void visit( PrototypeAST & ) = 0;
  virtual void visit( VariableExprAST & ) = 0;



  // virtual void visit( BinaryExprAST const& ) = 0;
  // virtual void visit( CallExprAST const& ) = 0;
  // virtual void visit( FunctionAST const& ) = 0;
  // virtual void visit( NumberExprAST const& ) = 0;
  // virtual void visit( PrototypeAST const& ) = 0;
  // virtual void visit( VariableExprAST const& ) = 0;

};

#endif