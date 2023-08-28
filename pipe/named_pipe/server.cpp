#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

#define MODE 0666 //权限
#define SIZE 128

string ipcPath = "./fifo.ipc";

int main()
{
    //1.创建管道文件
    if(mkfifo(ipcPath.c_str(),MODE)<0)
    {
        perror("mkfifo");
        //exit(1);
    }
    cout << ("创建管道文件成功")<<"step 1"<<endl;
    //2.正常的文件操作
    int fd=open(ipcPath.c_str(),O_RDONLY);
    if(fd<0)
    {
        perror("open");
        exit(2);
    }
    cout << ("打开管道文件成功")<<"step 2"<<endl;
    //3.编写正常的通信代码
    char buffer[SIZE];
    while(true)
    {
        memset(buffer,'\0',sizeof(buffer));
        ssize_t s=read(fd,buffer,sizeof(buffer)-1);//读取到内存要注意最后一个是/0
        if(s>0)
        {
            cout<<"client say:  "<<buffer<<endl;
        }
        else if(s==0)
        {
            //读到了文件结尾
            cerr<<"read end of file, client quit ,server quit too"<<endl;
            break;
        }
        else
        {
            //读取失败
            perror("read");
            break;
        }
 
    } 
    //4.关闭文件
    close(fd);
    cout << ("关闭管道文件成功")<<"step 3"<<endl;
    unlink(ipcPath.c_str());//通信完毕  就删除管道文件
    cout << ("删除管道文件成功")<<"step 4"<<endl;
    return 0;
}
