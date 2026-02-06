#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
//#include <stdlib.h>
void my_wc(int fd,int *line_c,int *word_c,int *char_c);

int main(int argc,char *argv[])
{
	char ret;
	int word_f=0,char_f=0,line_f=0;
	int word_c=0,char_c=0,line_c=0;
	int word_total=0,char_total=0,line_total=0;
	int file_count=0;
	
	while((ret=getopt(argc,argv,"lwc") )!=-1)
	{
	 
	 //printf("%c ",ret);
	 
	 switch(ret)
	 {
	 case 'w':
	 word_f=1;
	 break;
	 
	 case 'c':
	 char_f=1;
	 break;
	 
	 case 'l':
	 line_f=1;
	 break;
	}
	
	}
	
	for(int i=optind;argv[i];i++)
	{
		file_count++;
		int fd = open(argv[i],O_RDONLY);
		
		 word_c=0,char_c=0,line_c=0;
		
		my_wc(fd,&line_c,&word_c,&char_c);
		
		//print
		
		if (line_f) printf("%d ", line_c);
		if (word_f) printf("%d ", word_c);
		if (char_f) printf("%d ", char_c);

		
		if(word_f==0 && char_f==0 && line_f==0)
		printf("count-> %d %d %d ",line_c,word_c,char_c);
		
		printf("%s\n",argv[i]);
		
		line_total+=line_c;
		word_total+=word_c;
		char_total+=char_c;
		
		
	}
	
	
	if(file_count > 1)
	{
	printf("%d %d %d total\n",line_total,word_total,char_total);
	}
	
	if( argv[optind] == NULL)
	{
		my_wc(0,&line_c,&word_c,&char_c);
		
		printf("\n%d %d %d \n",line_c,word_c,char_c);	
		
	}
	
	
	
	
}	
void my_wc(int fd,int *line_c,int *word_c,int *char_c)
{
	char buff,prev=' ';
	while(read(fd,&buff,1)>0)
	{
		(*char_c)++;
		
		if(buff =='\n')
		(*line_c)++;
		
		if( buff ==' ' && prev !=' '  ||  buff=='\n')
		{
			
			(*word_c)++;
		}
		
		prev=buff;
				
	}

}
	


