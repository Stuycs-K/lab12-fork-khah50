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

  /*
  int number;
  char buff[sizeof(int)+1];
  int fd = open("/dev/random", O_RDONLY, 0);


  buff[sizeof(int)] = 0;
  read(fd, buff, sizeof(int));
  number = *(int*)buff;
  close(fd);
  int childPid = 10;

  printf("%d %dsec\n", childPid, number);
  sleep(number);
  printf("%d finished after %dsec\n", childPid, number);

*/
