#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include "fork.h"

void forkChild(){
  pid_t childOne, childTwo;
  int sleepOne, sleepTwo;
  int status; 

  printf("%d about to create 2 child processes\n", getpid());

  childOne = fork();
  if(childOne < 0){
    perror("fork fail");
    exit(1);
  }

  if(childOne == 0){
    srand(getpid());
    sleepOne = rand() % 5 + 1;
    printf("%d %dsec\n", getpid(), sleepOne);
    sleep(sleepOne);
    printf("%d finished after %dsec\n", getpid(), sleepOne);

    exit(sleepOne);
  }

  childTwo = fork();
  if(childTwo < 0){
    perror("fork fail");
    exit(1);
  }
  
  if(childTwo == 0){
    srand(getpid());
    sleepTwo = rand() % 5 + 1;
    printf("%d %dsec\n", getpid(), sleepTwo);
    sleep(sleepTwo);
    printf("%d finished after %dsec\n", getpid(), sleepTwo);

    exit(sleepTwo);
  }

  pid_t exit = wait(&status);

  if(WIFEXITED(status)){
    int timeSleep = WEXITSTATUS(status);
    printf("Main Process %d is done. Child %d slept for %dsec\n", getpid(), exit, timeSleep);
  }
}
