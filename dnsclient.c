// Client Program : dnsclient.c

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
int main()
{
    struct sockaddr_in server,client;
  
    int s,n;
   
    char *endd = "Y";
    char data[100],input[100],end[10];
    s=socket(AF_INET6,SOCK_DGRAM,0);
    server.sin6_family=AF_INET6;
    server.sin6_port=3000;
    server.sin6_addr.s_addr=inet6_addr("fe80::a00:27ff:fe94:1e4d");
    n=sizeof(server);
    while (strcmp(end,endd))
	{
    	printf("\nEnter your domain name system (DNS): ");
    	scanf("%s",input);
    	sendto(s,input,sizeof(input),0,(struct sockaddr *)&server,n);
    	recvfrom(s,data,sizeof(data), 0,NULL,NULL);
    	printf("%s \n",data);
	printf("Do you want to stop (Y/N)?");
	scanf("%s",end);
	} 
}
