#ifndef UTILS_H
#define UTILS_H

#include <cstdio>

inline void log_error(const char *str)
{
  fprintf(stderr, "Log error: %s\n", str);
}

#endif