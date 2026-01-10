#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int *p = static_cast<int *>((malloc(sizeof(int))));
  assert(p != NULL);

  printf("(%d) address of p: %08x\n", getpid(), (unsigned)*p); // a2
  
  *p = 0;                                                      // a3
  while (1) {
    // Spin(1);
    *p = *p + 10000;
    printf("(%d) p: %d\n", getpid(), *p); // a4
  }
  return 0;
}