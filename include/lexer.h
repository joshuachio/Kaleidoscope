#ifndef LEXER_H

#define LEXER_H

// #include <stdlib.h>
#include <cstdlib>
#include <string>
#include <vector>

enum Token
{
  tok_eof = -1,

  tok_def = -2,
  tok_extern = -3,

  tok_identifier = -4,
  tok_number = -5,
};


#endif