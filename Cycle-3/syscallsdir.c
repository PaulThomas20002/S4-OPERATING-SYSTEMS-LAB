/*AIM:
To write C Programs using the following system calls of UNIX operating system fork, exec,
getpid, exit, wait, close, stat, opendir, readdir.
1. PROGRAM FOR SYSTEM CALLS OF UNIX OPERATING SYSTEMS (OPENDIR,
READDIR, CLOSEDIR)
ALGORITHM:
STEP 1: Start the program.
STEP 2: Create struct dirent.
STEP 3: declare the variable buff and pointer dptr.
STEP 4: Get the directory name.
STEP 5: Open the directory.
STEP 6: Read the contents in directory and print it.
STEP 7: Close the directory.
PROGRAM:*/


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

struct dirent *dptr;

int main (int argc, char *argv[]){
        char buff[100];
        struct stat stats;
        DIR *dirp;
        printf("Enter the directory name : ");
        scanf("%s", buff);

        if((dirp=opendir(buff)) == NULL){
        printf("The given directory doesnot exist \n");
        exit(1);
        }

        while(dptr = readdir(dirp)){
        printf("%s\n", dptr->d_name);
        }
closedir(dirp);
}
