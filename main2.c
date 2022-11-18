/  main2.c
//  Collaboration with Mary Nwosu 
//  Finished on 10/22/22.
#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#define   MAX_COUNT  10

void  ChildProcess(void);     /* child process prototype  */
void  ParentProcess(int);     /* parent process prototype */
void  main() {
  pid_t  pid, pid2;
  int i, status;
    
  for (i = 0; i < 2; i++) {
    pid = fork();             // p1 created c1 & c2
    if (pid < 0)
      printf("Error: Fork Op Oops!\n");
    else if (pid == 0) {
      ChildProcess();
      exit(0);
    }
  }

  for (i = 0; i < 2; i++) {
    wait(&status);
    ParentProcess(status);
  }
}

void  ChildProcess() {
  int i, loop_count;
  pid_t  cpid, ppid;
  cpid = getpid();
  ppid = getppid();
  
  srand(getpid());
  loop_count = rand()%31;

  for (i = 0; i < loop_count; i++) {
    printf("Child Pid: %d is going to sleep!\n", cpid);
    sleep( rand()%MAX_COUNT );
    printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", cpid, ppid);
  }
}

void  ParentProcess(int status) {
  pid_t cpid;
  cpid = getpid();

  wait(&status); printf("Parent Pid: %d has completed!\n", cpid);
  printf("*** Parent is done, Child exited with exit status %d ***\n", WEXITSTATUS(status));
}