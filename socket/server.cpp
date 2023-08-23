#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "usage: " << argv[0] << " <port>" << endl;
		exit(1);
	}

	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	// 创建套接字
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
	{
		cout << "socket() error!" << endl;
		exit(1);
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	// 绑定IP地址和端口号
	if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
	{
		cout << "bind() error!" << endl;
		exit(1);
	}

	// 在IP和端口上进行监听
	if (listen(serv_sock, 5) == -1)
	{
		cout << "listen() error!" << endl;
		exit(1);
	}

	// 接收来自客户端的连接请求
	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1)
	{
		cout << "accpet() error!" << endl;
		exit(1);
	}

	// 利用通信套接字，向客户端发送数据
	char message[] = "Hello client, it's server!";
	write(clnt_sock, message, sizeof(message));

	// 通用通信套接字，接收客户端发送的数据
	char message1[100];
	int str_len = read(clnt_sock, message1, sizeof(message1) - 1);
	cout << "Message from client: " << message1 << endl;
       cout << "server side, client fd: " << clnt_sock << endl;
       cout << "server side, server fd: " << serv_sock << endl;
	
	// 关闭套接字
	close(clnt_sock);
	close(serv_sock);

	return 0;
}

