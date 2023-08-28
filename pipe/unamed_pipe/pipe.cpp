#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
 
using namespace std;
int main()
{
    //1、创建管道
    int pipefd[2]={0};
    //默认是 pipefd[0]为 读入端 pipefd[1]为写入端 放的是文件描述符
    int n = pipe(pipefd);
    assert(n != -1);
    (void)n;
    // assert在release端下没用 为了防止n只定义未使用而在release下报错
    //
    cout << "pipefd[0]:" << pipe[0] << endl<< "pipefd[1]:" << pipefd[1] << endl;
    //  文件描述符为 2 和 4
 
    //2、创建子进程
    pid_t id = fork();
    assert(id != -1);
    if(id==0)
    {
        //3、构建单向通信的通道，父进程写入，子进程读取。
        //3.1 关闭子进程不需要的fd
        close(pipefd[1]);
 
        //
        char buffer[1024];
        while(true)
        {
            ssize_t s = read(pipefd[0],buffer,sizeof(buffer)-1);
            if(s>0)
            {
                buffer[s]=0;
		//因为系统调用的Read不添加\0 我们手动添加
                cout<<"Father#"<<buffer<<endl;
            }
        }
 
        exit(0);
    }
    //父进程
    close(pipefd[0]);
    string message="现在是父进程，正在发送消息";
    int count=0;
    char sendbuffer[1024];
    while(true)
    {
        //构建一个变化的字符串
        snprintf(sendbuffer,sizeof(sendbuffer),"%s:%d",message.c_str(),count);
 
        //写入
        write(pipefd[1],sendbuffer,strlen(sendbuffer));
        sleep(1);
    }
    pid_t ret=waitpid(id,nullptr,0);
    assert(ret<0);
    (void)ret;
    close(pipefd[1]);
 
    return 0;
}
