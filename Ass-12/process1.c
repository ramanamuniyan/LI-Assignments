// ASS 12 shm 


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/shm.h>



int main()

{

	//create the SHM
        int shmid = shmget('A',100,IPC_CREAT | 0644);

        //Attach the process with SHM
        char *ptr = shmat(shmid,NULL,0);
        
        if(ptr == (void *)-1)
        {
        perror("ptr error");
         return 1;
	}
	
	printf("Enter the String :");
	
	char str[50];
	
	scanf("%s",str);
	
	//fgets(str,sizeof(str),stdin);
	
	//printf("The Entered value  is %s",str);
	
	
	
	int i=0;
	
	while(str[i] !='\0')
	{
	
	//puts("1");
	if(isalpha(str[i]))
	
	str[i]= toupper(str[i]); //  to upper case
	
	i++;
	
	}
	
	//puts("here");
	 //copy the string into SHM
        strcpy(ptr,str);

	
	
	sleep(5);
	
	
	
	strcpy(str,ptr);
	
	printf("The Output is %s\n",ptr);
	
	
	shmdt(ptr);
	
		
	shmctl(shmid,IPC_RMID,NULL);
	



}
