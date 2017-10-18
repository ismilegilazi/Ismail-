#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h> //strlen
#include<sys/socket.h>
#include<arpa/inet.h>  //inet_addr
#include<unistd.h>  //write
#include<stdlib.h>

int main(int argc , char *argv[])
{
	//variables 
	
	int welcomeSocket,newSocket;
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	char message[2000];
	welcomeSocket = socket(PF_INET,SOCK_STREAM,0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port =htons( 7000);
	serverAddr.sin_addr.s_addr = inet_addr("192.168.199.129");
	memset(serverAddr.sin_zero, '\0' , sizeof serverAddr.sin_zero);
	bind(welcomeSocket, (struct sockaddr*)&serverAddr,sizeof(serverAddr));
	if(listen(welcomeSocket,5)==0)
	{
	
		printf("Listening\n");
	
	
	
		addr_size=sizeof serverStorage;
		newSocket = accept (welcomeSocket, (struct sockaddr *)&serverStorage, &addr_size);
		strcpy(message,"Hello\n");
		send(newSocket,message,13,0);
	



	return 0;
	}
}



