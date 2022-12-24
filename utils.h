#pragma once
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define jointk(a, b) a##b
#define fetch(name, result, args)                                              \
  result(*jointk(libc_, name)) args;                                           \
  jointk(libc_, name) = dlsym(RTLD_NEXT, #name);                               \
  if (name == NULL) {                                                          \
    puts("fake-home: Failed to get " #name " from system libc");               \
    abort();                                                                   \
  }
