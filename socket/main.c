#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr

int main(int argc , char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message , server_reply[2000];
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
		
	server.sin_addr.s_addr = inet_addr("125.212.195.45");
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );

	//Connect to remote server
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	
	puts("Connected\n");
	
	//Send some data
	message = "GET /ddns_ud?s=91842f1584789a2ef23aa9e9d2e12132&t=1594700436&u=dasanvn1&p=e10adc3949ba59abbe56e057f20f883e&a=192.168.9.99&d=onts.vddns.vn HTTP/1.0\r\n\r\n";
	if( send(socket_desc , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");
	
	//Receive a reply from the server
	if( recv(socket_desc, server_reply , 2000 , 0) < 0)
	{
		puts("recv failed");
	}
	puts("Reply received\n");
    char *content = strstr(server_reply, "\r\n\r\n");
if (content != NULL) {
    content += 4; // Offset by 4 bytes to start of content
}
else {
    content = server_reply; // Didn't find end of header, write out everything
}
    printf("data reply from server is %d\n", atoi(content));
	
	return 0;
}
