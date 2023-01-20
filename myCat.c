/*
 * mycat.c : making command 'cat' myself
 * @author : Jeong kyu won
 * @student_id : 32204027
 * @email : 32204027@dankook.ac.kr
 * @version : 1.0
 * @date : 2022. 10. 29
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 32

int main(int argc, char* argv[]){
	int fd, read_size, write_size;
	char buf[MAX_BUF];

	if(argc!=2){
		printf("USAGE : %s file_name_for_cat\n", argv[0]);
		exit(-1);
	}//endif


	fd=open(argv[1], O_RDONLY);

	if(fd<0){
		printf("\"mycat\" command is stopped with error number %d\n",errno);
		exit(-1);
	}//endif

	while(1){
		read_size=read(fd,buf,MAX_BUF);
		if(read_size==0){
			break;
		}//endif
		write_size=write(STDOUT_FILENO,buf,read_size);
	}//endwhile

	close(fd);

	return 0;
}//endmain
