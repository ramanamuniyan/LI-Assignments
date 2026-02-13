#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
void my_handler(int signum,siginfo_t *info, void *ptr)
{

	if(signum == SIGSEGV)
	{
	
	printf(" the fault addr ->%p",info->si_addr);
	exit(0);
	}	
	
}

int main()
{

	printf("Pid -> %d",getpid());
	
	struct sigaction new_act;
	
	//initialize the value
	memset(&new_act,0,sizeof(new_act)); 
	
	new_act.sa_sigaction=my_handler;
	
	new_act.sa_flags=SA_SIGINFO;
	
	//sigaddset(&new_act.sa_ma
	
	sigaction(SIGSEGV,&new_act,NULL);
	
	int *ptr=NULL;
	
	*ptr=0;
	
	

}

