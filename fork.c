#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include "fork.h"


void child(int childPID){
  srand(time(NULL));
  int number = rand() % 5 + 1;
  printf("%d %dsec\n", childPID, );
  sleep(number);
  printf("%d finished after %dsec\n", childPID, number)
}

void fork(){
  srand(time(NULL));
  pid_t parentPID = getpid();
  printf("%d about to create 2 child processes", parentPID);

  pid_t childOne = fork();
  if(childOne == 0){
    child(getpid());
    exit(0);
  }

}
