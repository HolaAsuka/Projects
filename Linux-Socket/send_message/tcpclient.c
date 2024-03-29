/**********************************************************\
*                                                         *\
*  program name:tcpclient.c                               *
*  Author:Liang gang & Hu Xiao-qin                        *\
*  Funtion:This program is just a demostrate program      *\
*          to tell students how to use socket to          *\
*          make a tcp communation.                        *\
*  Date: 03-06-2009                                       *\
*                                                         *\
***********************************************************/


#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 8900

void print_usage(char * cmd)
{
	fprintf(stderr," %s usage:\n",cmd);
	fprintf(stderr,"%s IP_Addr [port]\n",cmd);

}


int main(int argc,char** argv)
{
	struct sockaddr_in server;
	int ret;
	int len;
	int port;
	int sockfd;
	int sendnum;
	int recvnum;
	char send_buf[2048];
	char recv_buf[2048];

	if ((2>argc)|| (argc >3))
	{
		print_usage(argv[0]);
		exit(1);

	}

       if (3==argc) 
       {
		port = atoi(argv[2]);
       }

    	if (-1==(sockfd=socket(AF_INET,SOCK_STREAM,0)))
	{
		perror("can not create socket\n");
		exit(1);
	}

	memset(&server,0,sizeof(struct sockaddr_in));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_port = htons(port);

	if (0>(ret=connect(sockfd,(struct sockaddr*)&server,sizeof(struct sockaddr))))
	{
		perror("connect error");
		close(sockfd);
		exit(1);

	}

	//memset(send_buf,0,2048);
	//memset(recv_buf,0,2048);

	printf("what words do  you want to tell to server:\n");
	gets(send_buf);

        #ifdef DEBUG
		printf("%s\n",send_buf);
  		#endif 

	//sprintf(send_buf,"i am lg,thank for your servering\n");

	if (0>(len=send(sockfd,send_buf,strlen(send_buf),0)))
	{
		perror("send data error\n");
		close(sockfd);
		exit(1);

	}

	if (0>(len=recv(sockfd,recv_buf,2048,0)))
	{
		perror("recv data error\n");
		close(sockfd);
		exit(1);
	}
	
	recv_buf[len]='\0';

	printf("the message from the server is:%s\n",recv_buf);
	close(sockfd);

}




