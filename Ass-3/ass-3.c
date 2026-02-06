#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void my_dup(int , char*,char*);
void my_dup2(int fd, char *str1, char *str2)
int main(int argc,char *argv[])
{
    
    int fd;
   
   
   fd = open(argv[1],O_WRONLY |O_CREAT | O_TRUNC,0644);
   
   printf("1.dup\n2.dup2\n Enter the num.");
   
   int num;
   scanf("%d",&num);
   
   char str1[]="ramana",str2[]="muniyan";
   
   
   switch(num)
   {
       case 1:
       
       my_dup(fd,str1,str2);
       break;
       
       case 2:
       
      my_dup2(fd,str1,str2);
       break;
   }
    
}
void my_dup(int fd, char *str1, char *str2) {
    int save_std = dup(1);    // Save original stdout
    close(1);                 // Close stdout
    dup(fd);                  // Duplicates fd to fd 1 (stdout)
    printf("%s", str1);
    fflush(stdout);           // Force output to file

    close(1);                 // Close redirected stdout
    dup(save_std);            // Restore original stdout (becomes fd 1)
    close(save_std);          // Clean up save descriptor
    printf("%s", str2);
}   

void my_dup2(int fd, char *str1, char *str2) {
    int save_std = dup(1);        // Save original stdout
    dup2(fd, 1);                  // Redirect stdout to fd
    printf("%s", str1);
    fflush(stdout);               // Force output to file

    dup2(save_std, 1);            // Restore original stdout
    close(save_std);              // Clean up
    printf("%s", str2);
}   
