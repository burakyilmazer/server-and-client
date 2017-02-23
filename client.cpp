#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in server;
	char message[1000], server_reply[2000];
	sock=socket(AF_INET, SOCK_STREAM, 0);
	if(sock==-1)
	{
		printf("socket olusturulamiyor");
	}
	puts("soket olusturuldu");
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	serer.sin_family=AF_INET;
	server.sin_port=htons(8888);
	if(connect(sock, (struct sockaddr *)&server, sizeof(server))<0)
	{
		perror("baglanti hataasi");
		return 1;
	}
	puts("baglanti kuruldu\n");
	while(1)
	{
		printf("mesaj gir: ");
		scanf("%s",message);
		if(send(sock, message, strlen(message),0)<0)
		{
			puts("mesaj iletilemedi");
			return 1;
		}
		if(recv(sock, server_reply, 2000,0)<0)
		{
			puts(éokuma hatasi);
			break;
		}
		puts("server cevabi: ");
		puts(server_reply);
	}
	close(sock);
	return 0;
}
