#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	int fd;
	char buf[14];
	fd = open ("myfile.txt", O_CREAT|O_WRONLY, 0600);
	if ( fd == -1 ){
		printf( "\n Couldn't create and open file \n" );
		exit(1);
	}
	write ( fd, "Hi,,,,,,,,Hello World!\n", 13);
	close ( fd );

	fd = open ( "myfile.txt", O_RDONLY);
	if ( fd == -1 ){
	 	printf ( "\nCouldn't open file and read file\n" );
		exit(1);
    	}
    	read ( fd, buf, 13 );
    	buf[13] = '\0' ;
	close ( fd );
    	printf ( "%s\n", buf);
    	return 0;
}
