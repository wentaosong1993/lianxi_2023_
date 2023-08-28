#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

string ipcPath = "./fifo.ipc";

int main()
{
    //1、读取管道文件
    int fd=open(ipcPath.c_str(),O_WRONLY);
    if(fd<0)
    {
        //打开失败
        perror("open");
        exit(1);
    }
    //2.ipc过程
    string buffer;
    while(true)
    {
        cout<<"Please Enter Message Line :>";
        getline(cin,buffer);//命名写到了buffer里面
        write(fd,buffer.c_str(),sizeof(buffer));//写到文件里 这里不用-1 因为文件里面不看/0
    }
    //3.关闭
    close(fd);
    return 0;
}
