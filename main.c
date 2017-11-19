#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main(){
  printf("Parent before fork: %d\n", getpid());
  int a = getpid();
  int b = fork();
  if(getpid() == a){
    b = fork();
    int status;
    int finished = wait(&status);
    if(status){
      printf("Parent: child %d slept %d\n", finished, WEXITSTATUS(status));
    }
  }

  if(!b){
    printf("Child: %d\n", getpid());
    int t = rand() % 16 + 5;
    sleep(t);
    printf("Child %d finished\n", getpid());
    return t;
  }

  return 0;
}
