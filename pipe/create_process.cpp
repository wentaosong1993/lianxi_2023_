#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        // 父进程
        printf("This is the parent process. PID: %d\n", getpid());
    } else if (pid == 0) {
        // 子进程
        printf("This is the child process. PID: %d\n", getpid());
    } else {
        // fork()失败
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }
    
    return 0;
}

