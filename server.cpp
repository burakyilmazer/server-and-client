#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(int argc, char *arg[])
{
	int socket_deesc, client_sock, c, read_size;
	struct sockaddr_in server, client;
	char client_message[2000];
	socket_desc=socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc==-1)
		printf("could not create socket");
	puts("socket  created");
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(8888);
	if(bind(socket_desc, (struct sockaddr*)&server, sizeof(server))<0)
	{
		perror("bind hatasi");
		return 1;
	}
	puts("baglanti basarili");
	while((read_size=recv(client_sock, client_message,2000,0))>0)
	{
		write(client_sock,client_message, strlen(client_message)),
	}
	if(reaad_size==0)
	{
		puts("client ayrildi");
		fflush(stdout);
	}
	else if(read_size==-1)
	{
		perror("okuma hatasi");
	}
	return 0;
}
