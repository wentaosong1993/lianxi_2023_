#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        std::cerr << "Failed to create pipe" << std::endl;
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        std::cerr << "Failed to create child process" << std::endl;
        return 1;
    }

    if (pid > 0) {
        // Parent process
	// pid > 0 ,说明是父进程；pid = 0,说明是子进程； pid < 0，说明创建子进程失败。
        close(fd[0]); // Close the read end of the pipe

        std::string message = "Hello from parent process!";
        write(fd[1], message.c_str(), message.length() + 1);

        close(fd[1]); // Close the write end of the pipe
    } else {
        // Child process
        close(fd[1]); // Close the write end of the pipe

        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        std::cout << "Message from parent process: " << buffer << std::endl;

        close(fd[0]); // Close the read end of the pipe
    }

    return 0;
}
