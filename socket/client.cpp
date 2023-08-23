#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "usage: " << argv[0] << " <IP> <port>" << endl;
		exit(1);
	}

	int client_sock;
	//int server_socket;
	struct sockaddr_in serv_addr;

	// 创建套接字
	client_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (client_sock == -1)
	{
		cout << "socket() error!" << endl;
		exit(1);
	}

	// 初始化地址信息
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	// 向服务器端发起连接请求
	if (connect(client_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		cout << "connect() error!" << endl;
		exit(1);
	}

	// 通过通信套接字client_sock, 读取来自服务器端的数据
	char message[100];
	int str_len = read(client_sock, message, sizeof(message) - 1);
	if (str_len == -2)
	{
		cout << "read() error!" << endl;
		exit(1);
	}
	
	// 通过通信套接字client_sock, 向服务器传输数据
	char sendMessage[] = "Hello server, it's client!";
	int str_len1 = write(client_sock, sendMessage, sizeof(sendMessage));
	cout << "Message from server: " << message << endl;
	cout << "client's socket fd:" << client_sock  << endl;

	// 关闭套接字
	close(client_sock);
	return 0;
}

