#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

void print(int fd_1);
int main()
{

	int ret= fork();
	
	if(ret>0)
	{
	
	//parent
	
	sleep(50);
	printf("child is zombie\n ");
int ret2=fork();
	
	if(ret2>0)
	{
	//parent 
	
	
	}
	else if(ret == 0)
	{
	//chid2 to check the parent is completed;
	
	//print the 
	
	int pid1=getppid();
	
	sleep(2);
int pid2=getppid();
	
	if(pid1 != pid2)
	{
	// orphan
	
	char ps[16];
	
	snprintf(ps,sizeof(ps),"%d",getpid);
	char file[20]="/proc/";
	
	
	strcat(file,ps);
	
	strcat(file,"/status");
	
	
	int fd_1=open(file,O_RDONLY);
	
	print(fd_1);
	

	}
	
	}
	
	
	}
	
	else if(ret==0)
	{
	
	//child 
	
	
	int rets=getppid();
	printf("The parent pid is -> %d\n",rets);
	//printf("child is running\n");
	
	char ps[16];
	
	snprintf(ps,sizeof(ps),"%d",getpid);
	char file[20]="/proc/";
	

	strcat(file,ps);
	
	strcat(file,"/status");
	
	
	int fd_1=open(file,O_RDONLY);
	
	print(fd_1);
	sleep(25);
	
	
	
	}
}

void print(int fd)
{
	char buf[256];
	int bytes, lines = 0;

	while ((bytes = read(fd, buf, sizeof(buf))) > 0) {
    	for (int i = 0; i < bytes; i++) 
    	{
        write(1	, &buf[i], 1);

        if (buf[i] == '\n') 
        {
            lines++;
            if (lines == 3)
                return;   // stop after 3 lines
        }
    }
}
	

}

