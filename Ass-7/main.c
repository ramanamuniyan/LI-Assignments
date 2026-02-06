#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{

	if(argc < 2)
	{
	
	printf("Usage %s args\n",argv[0]); // error message
	
	return 1;
	}
	
	int status;
	int ret=fork();
	
	if(ret > 0)
	{
	//parent 
	
	wait(&status);
	if(WIFEXITED(status))
	{
	
	printf("The child status is %d\n",WEXITSTATUS(status));
	
	}
	
	
	}
	
	else if(ret ==0)
	
	{
	 
	 // child process 
	 
	 printf("The child process id %d\n",getpid()); //printing the child process
	execvp(argv[1],argv+1);//execute the cmd inside the child process
	
	
	
	
	}
	

}

