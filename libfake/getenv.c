#include "../config.h"
#include "../utils.h"
#include <stdlib.h>
#include <string.h>

char *getenv(const char *name) {
  fetch(getenv, char *, (const char *));
  char *result = NULL;

  if (strcmp(name, "HOME") == 0) {
    result = FK_HOME_DIR;
  } else {
    result = libc_getenv(name);
  }

  dlclose(libc_getenv);

  return result;
}