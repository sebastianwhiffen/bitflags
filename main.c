#include <stdio.h>
#include <unistd.h>

int cvar_modifiedFlags;
#define CVAR_ARCHIVE 0x0001

void frame() {

  int res = cvar_modifiedFlags & CVAR_ARCHIVE;

  printf("res: %d \n", res);

  if ((cvar_modifiedFlags & CVAR_ARCHIVE)) {
    printf("flags modified \n");
    return;
  }
  printf("no flags modified \n");
  cvar_modifiedFlags &= ~CVAR_ARCHIVE;
}

int main() {

  cvar_modifiedFlags &= ~CVAR_ARCHIVE;

  cvar_modifiedFlags |= CVAR_ARCHIVE;
  while (1) {

    frame();

    usleep(16000);
  }
}
