#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc,char  *argv[])
{
	if(argc < 3)
	{
	// checking the arguments and pipe is present or not.
	perror("./a.out cmd [options] | cmd [options]");
	return 0;
	}
	
	int i=0;int pipe_index[2];int k=0;int flag=1;
	while( argv[i] != NULL ) //loop run up to null
	{
	
	if(strcmp(argv[i],"|") ==0)  //checking for the pipe is present 
	{
	argv[i]=NULL;  // replacing pipe with null
	pipe_index[k++]=i;
	
	flag=0;
	
	}
	i++;
	}
	
	
	if(flag)
	{
	
	perror("pipe is not present");
	return 0;
	//exit();
	}
	int pipe_fd[2];
	
	// creating the pipe.
	pipe(pipe_fd); 
	
	// create a child1 process
	
	int ret=fork();
	
	if(ret > 0)
	{
	//parent 
	
	int ret2 =fork();
	
	if(ret2 >0)
	{
	
	//parent 
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);wait(NULL);
	
	
	}
	
	else if(ret2 ==0)
	{
	//child 2
	dup2(pipe_fd[0],0);  // make a copy of pipe read at the stdin at child 2 process..
	
	 close(pipe_fd[1]); //close the pipe write 
	 
	 execvp(argv[pipe_index[0]+1],(argv+pipe_index[0]+1)); //execute cmd
	}
	
	}
	 
	 else if(ret ==0)
	 {
	 //child 1
	 
	 dup2(pipe_fd[1],1);  //make a copy of pipe write at the stdout at child 1 process..
	 
	 close(pipe_fd[0]); //close the pipe write
	 
	 execvp(argv[1],argv+1); // execute the cmd upto null 
	 
	 
	 
	 
	 }
	 
	

}
