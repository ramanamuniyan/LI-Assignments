#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{

	int status;
	
	pid_t ret1=fork(); //creating the process
	
	if(ret1> 0)
	{
	//parent
	
	pid_t ret2=fork();
	
	if(ret2 >0)
	{
	//parent
	
	pid_t pid3=fork();
	
	if(pid3>0)
	{
	//parent 
	
	for(int i=0;i<3;i++)
	{
	pid_t cpid=wait(&status);
	
	if (WIFEXITED(status))
        {
        printf("Child %d is terminated with code %d\n",cpid, WEXITSTATUS(status));
        }
        
                                
	}
	
	
	}
	
	else if(pid3== 0)
	{
	//child3
	
	 printf("Child 3 with pid %d created\n",getpid());
                                return 0;
	}
	
	}
	
	else if(ret2==0)
	{
	//child2
	printf("Child 2 with pid %d created\n",getpid());
	
	}
	
	
	
	
	}
	else if(ret1 ==0)
	{
	//child 1
	printf("Child 1 with pid %d created\n",getpid());
	
	
	}
	
	else
	{
	perror("fork");
	return -1;
	}
	


}
