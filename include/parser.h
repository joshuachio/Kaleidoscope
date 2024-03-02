#ifndef PARSER_H
#define PARSER_H

#include "global.h"
#include "utils.h"
#include "lexer.h"
#include "AST/ExprAST.h"
#include "AST/PrototypeAST.h"
#include "AST/NumberExprAST.h"
#include "AST/VariableExprAST.h"
#include "AST/CallExprAST.h"
#include "AST/BinaryExprAST.h"
#include "AST/FunctionAST.h"

class Parser {
protected:
  // std::unique_ptr<Lexer> lexer = std::make_unique<Lexer>();
  std::unique_ptr<Lexer> lexer;
  int curTok;
  std::map<char, int> binopPrecedence;
  // std::map<char, int> binopPrecedence = {{'<' , 10}, {'+', 20}, {'-', 20}, {'*', 40}};

public:
  // Parser() : 
  //   lexer(std::make_unique<Lexer>()) {
  //   binopPrecedence['<'] = 10;
  //   binopPrecedence['+'] = 20;
  //   binopPrecedence['-'] = 20;
  //   binopPrecedence['*'] = 40;
  // };

  Parser(){
    lexer = std::make_unique<Lexer>();
    binopPrecedence['<'] = 10;
    binopPrecedence['+'] = 20;
    binopPrecedence['-'] = 20;
    binopPrecedence['*'] = 40;
  };

  ~Parser() {};

  // static std::unique_ptr<ExprAST> parseNumberExpr();
  // static std::unique_ptr<ExprAST> parseParenExpr();
  // static std::unique_ptr<ExprAST> parseIdentifierExpr();
  // static std::unique_ptr<ExprAST> parsePrimary();

  // static int getTokPrecedence();
  // static std::unique_ptr<ExprAST> parseExpression();
  // static std::unique_ptr<ExprAST> parseBinOpRHS(int exprPrec, std::unique_ptr<ExprAST> LHS);

  // static std::unique_ptr<PrototypeAST> parsePrototype();
  // static std::unique_ptr<FunctionAST> parseDefinition();
  // static std::unique_ptr<PrototypeAST> parseExtern();
  // static std::unique_ptr<FunctionAST> parseTopLevelExpr();

  // static void handleDefinition();
  // static void handleExtern();
  // static void handleTopLevelExpression();
  // static void parse();

  int getNextToken();

  std::unique_ptr<ExprAST> parseNumberExpr();
  std::unique_ptr<ExprAST> parseParenExpr();
  std::unique_ptr<ExprAST> parseIdentifierExpr();
  std::unique_ptr<ExprAST> parsePrimary();

  int getTokPrecedence();
  std::unique_ptr<ExprAST> parseExpression();
  std::unique_ptr<ExprAST> parseBinOpRHS(int exprPrec, std::unique_ptr<ExprAST> LHS);

  std::unique_ptr<PrototypeAST> parsePrototype();
  std::unique_ptr<FunctionAST> parseDefinition();
  std::unique_ptr<PrototypeAST> parseExtern();
  std::unique_ptr<FunctionAST> parseTopLevelExpr();

  void handleDefinition();
  void handleExtern();
  void handleTopLevelExpression();
  void parse();
};


#endif