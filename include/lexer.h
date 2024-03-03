#ifndef LEXER_H
#define LEXER_H

#include "global.h"

enum Token
{
  tok_eof = -1,

  tok_def = -2,
  tok_extern = -3,

  tok_identifier = -4,
  tok_number = -5,
};

class Lexer {
protected:
  std::string identifierStr;
  double numVal;
  char lastChar = ' ';

public:
  Lexer() {};
  ~Lexer() {};
  int gettok();
  double getNumVal() { return numVal; }
  std::string getIdentifierStr() {return identifierStr; }
};



#endif