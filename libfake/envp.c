// HERE'LL BE DRAGONS.

#include "../config.h"
#include "../utils.h"
#include <pwd.h>
#include <string.h>
#include <unistd.h>

char *real_user_home(void) {
  fetch(getpwuid, struct passwd *, (__uid_t));
  struct passwd *pw = libc_getpwuid(getuid());
  char *pwdir = pw->pw_dir;
  dlclose(libc_getpwuid);
  return pwdir;
}

int __libc_start_main(int *(main)(int, char **, char **), int argc,
                      char **ubp_av, void (*init)(void), void (*fini)(void),
                      void (*rtld_fini)(void), void(*stack_end)) {

  char **envp = ubp_av + argc + 1;
  char **current = envp;

  char *real_home = real_user_home();
  char *target = malloc(sizeof("HOME=") + strlen(real_home));
  strcpy(target, "HOME=");
  strcat(target, real_home);

  while (*current != NULL) {
    if (strcmp(*current, target) == 0) {
      char *fake = malloc(sizeof("HOME=") + sizeof(FK_HOME_DIR));
      strcpy(fake, "HOME=");
      strcat(fake, FK_HOME_DIR);

      *current = fake;

      break;
    }

    current++;
  }

  free(target);

  if (init) {
    init();
  }

  int res = (long)main(argc, ubp_av, envp);

  if (fini) {
    fini();
  }

  if (rtld_fini) {
    rtld_fini();
  }

  exit(res);
  return 0;
}