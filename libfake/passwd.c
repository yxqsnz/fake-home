#include "../config.h"
#include "../utils.h"
#include <pwd.h>
#include <string.h>
#include <sys/types.h>

struct passwd *getpwuid(__uid_t uid) {
  fetch(getpwuid, struct passwd *, (__uid_t));

  struct passwd *pw = libc_getpwuid(uid);
  strcpy(pw->pw_dir, FK_HOME_DIR);

  dlclose(libc_getpwuid);

  return pw;
}