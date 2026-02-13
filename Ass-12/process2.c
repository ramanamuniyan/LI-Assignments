// Ass -12


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	int shmid=shmget('A',100,0);
	
	char *ptr=shmat(shmid,NULL,0);
	
	char str[50];
	
	
	
	
	
	strcpy(str,ptr);
	
	//printf("before -> %s",str);
	
	int l=strlen(str);
        int i=0;
        while(i<l/2)
        {
        
        char temp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
        i++;
        
        }
        
     //  printf("reverse -> %s",str);
        
       // sleep(2);
        
        strcpy(ptr,str);
        
        
	shmdt(shmid);

}
