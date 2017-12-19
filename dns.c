#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<netdb.h>
int main()
{
    FILE *fp;
    struct sockaddr_in6 server,client;
    int s,n;
    char data[100],input[100],a[100];
    s=socket(AF_INET6,SOCK_DGRAM,0);
    server.sin6_family=AF_INET6;
    server.sin6_port=3000;
    server.sin6_addr.s_addr=inet6_addr("fe80::a00:27ff:fe94:1e4d");
    bind(s,(struct sockaddr *)&server,sizeof(server));
    n=sizeof(client);
    while(1)
    {
        strcpy(input,"");
        fp=fopen("dns.txt","r");
        recvfrom(s,data,sizeof data, 0,(struct sockaddr *)&client,&n);
        while(!feof(fp))
       {
           fscanf(fp,"%s",a);
           if(strcmp(a,data)==0)
          {
                fscanf(fp,"%s",input);
                break;
          }
      }
      if(strcmp(input,"")==0)
     {
           strcpy(input,"DNS given not found in database ..");
      }
     fclose(fp);
     sendto(s,input,sizeof input,0,(struct sockaddr *)&client,n);  
    }
}
