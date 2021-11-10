#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void signhandler(int signo){
  if (signo == SIGINT){
    int file = open("txt.data", O_WRONLY | O_CREAT | O_APPEND, 0644);
    char *thing = "program exited due to SIGINT";
    int written = write(file, thing, strlen(thing));
    close(file);
    exit(0);
  }
  if (signo == SIGUSR1){
    printf("parent PID: %d\n", getppid());
  }
}
int main() {
  signal(SIGINT, signhandler);
  signal(SIGUSR1, signhandler);
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}