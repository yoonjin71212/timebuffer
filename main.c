#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include "user/buffer_io.h"
int main (int argc, char **argv) {
 int fd;
	if(argc<2) {
		return 1;
	}
	if((fd=open(argv[1],O_RDWR))<0) {
		perror("Open error");
	}
  	ioctl(fd,__SORT_DESCENDING__,NULL);
	if(close(fd)) {
		perror("Close error");
	}
}
