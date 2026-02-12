#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()

{
	int  pipe_fd[2];	
	pipe(pipe_fd);  //creating the pipe 
	
	
	int ret=fork(); //creating child process
	
	if(ret>0)
	{
	//parent 
	
	close(pipe_fd[1]);
	char str2[50];
	
	read(pipe_fd[0],str2,sizeof(str2));  // reading the data from the pipe of child using the read
	
	
	int i=0;
	while(str2[i])
	{
	
	if(isalpha(str2[i]))
	str2[i]= toupper(str2[i]); //  to upper case
	i++;
	
	}


	printf("parent print :%s\n",str2); 
	
	//create the shm
	
	int shmid = shmget('A', 100, IPC_CREAT  | 0644);  // create the shm 
	
	void *ptr=shmat(shmid,NULL,0);  //attatch the shmid  process 
	
	strcpy(ptr,str2);  // copy because the mem shm is buff .
	
	shmdt(shmid);
	
	
	//shmctl(shmid,IPC_RMID,NULL);
		
		
	}
	else if(ret ==0)
	{
	//child
	
	char str[50];
	printf("Enter string child : ");
	scanf("%[^\n]",str);  // reading the data from the user.
	
	write(pipe_fd[1],str,strlen(str));   // write the data from the local var to the pipe.
	close(pipe_fd[0]);
	
	
	
	
	
	}

}

