#include <stdio.h>
#include <unistd.h>

// simple bit flags in c
// created as a short example for later usages.

//this is where we are storing the bitflags 
int modifiedFlags;

// flags must be multiples of 2
#define CVAR_USER 0x0001 /* 0000 0000 0000 0001 */
#define CVAR_CONFIG 0x0002
#define CVAR_SYS 0x0004

void frame() {

  if (modifiedFlags & CVAR_USER) {
    // do some user related updates in here each frame
    printf("user flag modified \n");

    //------------------------------------------------------------------------------------------
    //										   (the first time around)
    //		      modifiedFlags = 0000 0000 0000 0001 because the user changed flag was set.
    //
    //			 ~CVAR_USER = 1111 1111 1111 1110
    //
    // modifiedFlags AND ~CVAR_USER = 0000 0000 0000 0000


    // (see above bits ^^^^^^)
    // NOT to invert the respective bit flags
    // AND to set the respective flag off 
    // (because the inversion of the bit (NOT) can never return 1 using AND)
    modifiedFlags &= ~CVAR_USER;
  }

  if (modifiedFlags & CVAR_CONFIG) {
    printf("config flag modified \n");

    modifiedFlags &= ~CVAR_CONFIG;
  }

  if (modifiedFlags & CVAR_SYS) {
    printf("sys flag modified \n");
    modifiedFlags &= ~CVAR_SYS;
  }

  printf("no flags modified \n");
}

int main() {

  // simulate a flag changing in some system
  // OR is used here as to not unset values that have already been set.

  modifiedFlags |= CVAR_USER; /* cvar_modifiedFlags = 0000 0000 0000 0001 */
  // modifiedFlags |= CVAR_CONFIG; /* cvar_modifiedFlags = 0000 0000 0000 0011 */
  // modifiedFlags |= CVAR_SYS; /* cvar_modifiedFlags = 0000 0000 0000 0111 */

  while (1) {

    frame();

    usleep(16000);
  }
}
