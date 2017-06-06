#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

static void usage(const char *proc)
{
	printf("%s [ip] [port]\n",proc);
}

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		usage(argv[0]);
	}
	int listen_sock=startup(argv[1],atoi(argv[2]));
	struct sockaddr_in new_sock;
	socklen_t len=sizeof(new_sock);
	char buf[1024];
	while(1)
	{
		if(new_sock>0)
		{
			pid_t id=fork();
			if(id==0){
				while(1){
					ssize_t s=read(new_sock,buf,sizeof(buf)-1);
					if(s>0){
						buf[s-1]=0;
						write(new_sock,buf,sizeof(buf)-1);
					}
				}else{
					
				}

			}
		}
	}

	return 0;
}
