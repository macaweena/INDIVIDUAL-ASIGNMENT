#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message  , server_reply[2000];
	
	socket_desc = socket(AF_INET , SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("can't create socket");
	}
	server.sin_addr.s_addr = inet_addr("192.168.56.102");
	server.sin_family = AF_INET;
	server.sin_port = htons (22);

	if(connect(socket_desc, (struct sockaddr*)&server , sizeof(server))<0)
	{
		puts ("connection error");
		return 1;
	}
	puts ("connected");
	if (send (socket_desc, message, strlen(message),0)<0)
	{
		puts ("send failed");
		return 1;
	}
	puts ("data send");
	if (recv(socket_desc, server_reply, 2000,0) <0)
	{
		puts ("recv failed");
	}
	puts ("reply received");
	puts (server_reply);

	return 0;
}
