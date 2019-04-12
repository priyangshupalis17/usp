/* 4b1 */
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd1; 
    mkfifo("/home/student/1RV17IS065/myfifo", 0666); 
    char str1[80], str2[80]; 
    
    while(1)
    { 
        
        fd1 = open("/home/student/1RV17IS065/myfifo",O_WRONLY); 
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
        
        fd1 = open("/home/student/1RV17IS065/myfifo",O_RDONLY); 
        read(fd1, str1, 80);
        printf("%s\n", str1); 
        close(fd1); 
        
       
    } 
   
    return 0; 
}

/* 4b2 */
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd1,i; 
    mkfifo("/home/student/1RV17IS065/myfifo", 0666); 
    char str1[80], str2[80]; 
    
    while(1)
    { 
        fd1 = open("/home/student/1RV17IS065/myfifo",O_RDONLY); 
        read(fd1, str1, 80);
        printf("%s\n", str1); 
        close(fd1); 
        
        fd1 = open("/home/student/1RV17IS065/myfifo",O_WRONLY); 
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    } 
   
    return 0; 
} 
