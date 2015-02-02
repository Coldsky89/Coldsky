#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define MYPORT 3440

#define BACKLOG 10

int main()
{
int sockfd, new_fd;

struct sockaddr_in my_addr;

struct sockaddr_in their_addr;

int sin_size;

sockfd = socket(AF_INET, SOCK_STREAM, 0);

if (sockfd == -1)
{
perror("socket() error lol!");
exit(1);
}
else
{
printf("socket() is OK...\n");
}

my_addr.sin_family = AF_INET;
my_addr.sin_port=htons(MYPORT);
my_addr.sin_addr.s_addr=INADDR_ANY;

memset(&(my_addr.sin_zero), 0, 8);

if (bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) == -1)
{
perror("bind() error lol!");
exit(1);
}
else 
{
printf("bind() is ok...\n");
}

if (listen(sockfd, BACKLOG) == -1)
{
perror("listen() error lol!");
exit(1);
}
else
{
printf("listen() is OK...\n");
}

sin_size=sizeof(struct sockaddr_in);
new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);

if (new_fd == -1)
{
perror("accept() error lol!");
}
else
{
printf("accept() is OK...\n");
}

close(new_fd);
close(sockfd);


return 0;


}
