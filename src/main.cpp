#include "parser.h"

int main()
{
  std::unique_ptr<Parser> parser = std::make_unique<Parser>();
  parser->parse();
  // Parser::parse();
  return 0;
}