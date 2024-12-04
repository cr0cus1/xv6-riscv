#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv) {
   int pipe_fd[2];
   char buff[128];
   pipe(pipe_fd);

   if(fork() == 0) {
	close(pipe_fd[1]);
	read(pipe_fd[0], buff, sizeof(buff));
	int child_pid = getpid();
	printf("%d: received %s from parent \n", child_pid, buff);
   }
   else {
	close(pipe_fd[0]);
	write(pipe_fd[1], "1", sizeof("1"));
	int parent_pid = getpid();
	printf("%d: gived %s to child \n", parent_pid, buff);
   }
}
