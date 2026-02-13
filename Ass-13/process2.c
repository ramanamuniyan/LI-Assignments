//Ass 13


#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>
#include <unistd.h>
int main()
{
        //Get the SHMID
        int shmid = shmget('A',100,0);

        //Attach the process with SHM
        
        char *shm = shmat(shmid,NULL,0);

        //get the data from SHM
        char str[50];
        
        // opening the fifo file
        
        
      	int fd = open("myfifo", O_RDONLY);
        
        if(fd < 0)
    	{
        perror("fd error");
        return 1;
    	}

    printf("File opened\n");
        
        
        
         // reading from the fifo file
        
         read(fd,str,sizeof(str));
         
         
         close(fd);
        
        //strcpy(str,shm);

        //print it as a output
        
	printf("The readed data from SHM %s\n",str);
	
        
        
        
        int l=strlen(str);
        int i=0;
        while(i<l/2)
        {
        
        char temp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
        i++;
        
        }
        
        printf("The reversed data in process 2: %s\n",str);
        	
        	
        strcpy(shm,str);
        
        
        
       // puts("here");
        //dettach the process with SHM
        shmdt(shm);
        

        // shmctl(shmid,IPC_RMID,NULL);
        


}
