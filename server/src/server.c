#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	printf("Hello from server");
	return 0;
}