#include "parser.h"

int Parser::getNextToken()
{
  return curTok = lexer->gettok();
}

std::unique_ptr<ExprAST> Parser::parseNumberExpr()
{
  auto res = std::make_unique<NumberExprAST>(lexer->getNumVal());
  getNextToken();
  return std::move(res);
}

std::unique_ptr<ExprAST> Parser::parseParenExpr()
{
  getNextToken();
  auto x = parseExpression();
  if (!x)
    return nullptr;
  
  if (curTok != ')')
  {
    logError("expected ')'");
    return nullptr;
  }

  getNextToken();
  return x;
}

std::unique_ptr<ExprAST> Parser::parseIdentifierExpr()
{
  std::string idName = lexer->getIdentifierStr().c_str();
  getNextToken();

  if (curTok != '(')
    return std::make_unique<VariableExprAST>(idName);

  getNextToken();
  std::vector<std::unique_ptr<ExprAST>> args;
  if (curTok != ')')
  {
    while (true)
    {
      if (auto arg = parseExpression())
        args.push_back(std::move(arg));
      else
        return nullptr;

      if (curTok == ')')
        break;

      if (curTok != ',')
      {
        logError("Expected ')' or ',' in argument list");
        return nullptr;
      }

      getNextToken();
    }
  }

  getNextToken();
  return std::make_unique<CallExprAST>(idName, std::move(args));
}

std::unique_ptr<ExprAST> Parser::parsePrimary()
{
  switch (curTok)
  {
    default:
      logError("unknown token when expecting an expression");
      return nullptr;
    case tok_identifier:
      return parseIdentifierExpr();
    case tok_number:
      return parseNumberExpr();
    case '(':
      return parseParenExpr();
  }
}

int Parser::getTokPrecedence()
{
  if (!isascii(curTok))
    return -1;

  int tok = binopPrecedence[curTok];
  if (tok <= 0)
    return -1;
  return tok;
}

std::unique_ptr<ExprAST> Parser::parseExpression()
{
  auto LHS = parsePrimary();
  if (!LHS)
    return nullptr;
  
  return parseBinOpRHS(0, std::move(LHS));
}

std::unique_ptr<ExprAST> Parser::parseBinOpRHS(int exprPrec, std::unique_ptr<ExprAST> LHS)
{
  while (1)
  {
    int tok = getTokPrecedence();

    if (tok < exprPrec)
      return LHS;
    
    int binOp = curTok;
    getNextToken();

    auto RHS = parsePrimary();
    if (!RHS)
      return nullptr;

    int nextPrec = getTokPrecedence();
    if (tok < nextPrec)
    {
      RHS = parseBinOpRHS(tok + 1, std::move(RHS));
      if (!RHS)
        return nullptr;
    }

    LHS = std::make_unique<BinaryExprAST>(binOp, std::move(LHS), std::move(RHS));
  }
}

std::unique_ptr<PrototypeAST> Parser::parsePrototype()
{
  // printf("PROTO CURTOK: %d\n", curTok); // DELETE
  if (curTok != tok_identifier)
  {
    logError("Expected function name in prototype");
    return nullptr;
  }

  std::string functionName = lexer->getIdentifierStr().c_str();
  // printf("FUNCTION NAME: %s\n", functionName.c_str()); // DELETE
  getNextToken();
  // printf("CURTOK: %d\n", curTok); // DELETE
  if (curTok != '(')
  {
    logError("Expected '(' in prototype");
    return nullptr;
  }
  
  std::vector<std::string> params;
  while (getNextToken() == tok_identifier)
    params.push_back(lexer->getIdentifierStr().c_str());
  if (curTok != ')')
  {
    logError("Expected ')' in prototype");
    return nullptr;
  }
  
  getNextToken();
  return std::make_unique<PrototypeAST>(functionName, std::move(params));
}

std::unique_ptr<FunctionAST> Parser::parseDefinition()
{
  getNextToken();
  // printf("HERE\n"); // DELETE
  // printf("CURTOK: %d\n", curTok); // DELETE
  auto proto = parsePrototype();
  if (!proto)
    return nullptr;

  if (auto e = parseExpression())
    return std::make_unique<FunctionAST>(std::move(proto), std::move(e));
  return nullptr;
}

std::unique_ptr<PrototypeAST> Parser::parseExtern()
{
  getNextToken();
  return parsePrototype();
}

std::unique_ptr<FunctionAST> Parser::parseTopLevelExpr()
{
  if (auto e = parseExpression())
  {
    auto proto = std::make_unique<PrototypeAST>("", std::vector<std::string>());
    return std::make_unique<FunctionAST>(std::move(proto), std::move(e));
  }
  return nullptr;
}

void Parser::handleDefinition()
{
  // printf("DEFINITION\n"); // DELETE
  if (parseDefinition())
    fprintf(stderr, "Parsed a function definition.\n");
  else
    getNextToken();
}

void Parser::handleExtern()
{
  if (parseExtern())
    fprintf(stderr, "Parsed an extern\n");
  else
    getNextToken();
}

void Parser::handleTopLevelExpression()
{
  if (parseTopLevelExpr())
    fprintf(stderr, "Parsed a top-level expression\n");
  else
    getNextToken();
}

void Parser::parse()
{
  fprintf(stderr, "ready> ");
  getNextToken();
  // printf("CURTOK: %d\n", curTok); // DELETE
  while (1)
  {
    fprintf(stderr, "ready> ");
    switch (curTok)
    {
      case tok_eof:
        return;
      case ';':
        getNextToken();
        break;
      case tok_def:
        handleDefinition();
        break;
      case tok_extern:
        handleExtern();
        break;
      default:
        handleTopLevelExpression();
        break;
    }
  }
}