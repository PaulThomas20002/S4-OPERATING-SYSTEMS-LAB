#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

int pid, pid1, pid2, c_pid;
pid = fork();

if(pid == -1){
printf("Error in process creation\n");
exit(1);
}
if(pid != 0){
c_pid = wait(NULL);
pid1 = getpid();
printf("\n The parent process ID is %d\n", pid1);
}
else{
pid2 = getpid();
printf("The child process ID is %d\n", pid2);
}
}

