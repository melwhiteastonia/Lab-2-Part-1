//  main.c
//  Collaboration with Mary Nwosu 

#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

void  main(void) {
  pid_t  pid;
  int    i;
  char   buf[BUF_SIZE];

  pid = fork();
    
  for (i = 1; i <= MAX_COUNT; i++) {
    if (pid < 0)
      printf ("Oops!");
    else if (pid == 0) {
      sprintf(buf, "This is the pid %d and count = %d of the ChildProcess.\n", pid, i);
      write(1, buf, strlen(buf));
    }
    else {
      sprintf(buf, "This is the pid %d and count = %d of the ParentProcess.\n", pid, i);
      write(1, buf, strlen(buf));
    }
  }
}