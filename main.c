#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include "fork.h"

int main(){
  forkChild();
  return 0;
}
