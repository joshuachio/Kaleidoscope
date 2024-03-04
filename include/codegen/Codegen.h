#ifndef CODEGEN_H
#define CODEGEN_H

#include "ASTVisitor.h"
#include "global.h"
// #include "AST/BinaryExprAST.h"
// #include "AST/CallExprAST.h"
// #include "AST/FunctionAST.h"
// #include "AST/NumberExprAST.h"
// #include "AST/PrototypeAST.h"
// #include "AST/VariableExprAST.h"

class Codegen : public ASTVisitor {
public:
  void visit( BinaryExprAST const& ) override;
  void visit( CallExprAST const& ) override;
  void visit( FunctionAST const& ) override;
  void visit( NumberExprAST const& ) override;
  void visit( PrototypeAST const& ) override;
  void visit( VariableExprAST const& ) override;
};

#endif