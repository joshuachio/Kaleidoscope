#include "lexer.h"

int Lexer::gettok()
{
  // int lastChar = ' ';

  while (isspace(lastChar))
    lastChar = getchar();

  if (isalpha(lastChar))
  {
    identifierStr = "";
    while (isalnum(lastChar))
    {
      // printf("CHAR: %c\n", lastChar);
      identifierStr += lastChar;
      lastChar = getchar();
    }
    // while (isalnum(lastChar = getchar()))
    // {
    //   identifierStr += lastChar;
    // }
    // printf("TEST: %s\n", identifierStr.c_str());
    if (identifierStr == "def")
      return tok_def;
    if (identifierStr == "extern")
      return tok_extern;
    return tok_identifier;
  }

  if (isdigit(lastChar) || lastChar == '.')
  {
    std::string numStr;

    do
    {
      numStr += lastChar;
      lastChar = getchar();
    } while (isdigit(lastChar) || lastChar == '.');

    numVal = strtod(numStr.c_str(), 0);
    return tok_number;
  }

  if (lastChar == '#')
  {
    do
    {
      lastChar = getchar();
    } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

    if (lastChar != EOF)
    {
      return gettok();
    }
  }

  if (lastChar == EOF)
    return tok_eof;
  
  int thisChar = lastChar;
  lastChar = getchar();
  return thisChar;
}