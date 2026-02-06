#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
 int main(int argc,char *argv[])
{ 
   if(argc < 3)
   {
	   printf("./a.out [option -p] sourcefile destination_file");
	   return 0;
   }
   
   	

   int fd_src,fd_dst;
   char buffer;

	 fd_src  = open(argv[argc-2],O_RDONLY);

	 if(fd_src <0)
	 {
		 perror("Error in opening the src file");
		 return 0;
	 }

	 fd_dst= open(argv[argc-1],O_WRONLY | O_CREAT | O_TRUNC,0644);

	 if(fd_dst <0)
	 {
		 perror("Error in opening the dst file");
		 return 0;
	 }

	 while(read(fd_src,&buffer,1) >0)
	 {
		 write(fd_dst,&buffer,1);

	 }
	
	if( strcmp(argv[1] ,"-p")==0)
	{
	
		struct stat statbuf;
		
		fstat(fd_src,&statbuf);
		
		fchmod(fd_dst,statbuf.st_mode);
		
		
	}
	
	
	
	close(fd_src);
	close(fd_dst);
	
	
	

}



