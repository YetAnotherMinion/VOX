#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
//gives you htons()
#include <arpa/inet.h>

//locally defined files
#include "chunks.h"

int main(int argc, char *argv[])
{
	if(argc != 3) {
		printf("Usage: %s <address> <port>\n",argv[0]);
	}
	int socketfd, newsockfd, portno, client_length;
	struct sockaddr_in server_addr, client_addr;
	int n;
	char buffer[256];
	//open the socket
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	//ckeck that the socket is valid
	if(socketfd < 0) {
		printf("Error in socket creation\n");
		exit(1);
	}

	portno = atoi(argv[2]);
	server_addr.sin_family = AF_INET;
	//add the ip address of the socket
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	//convert the bost byte order and network byte order with htons()
	server_addr.sin_port = htons(portno);
	//we will need to recast the sockaddr_in struct to general
	//type sockaddr
	if(bind(socketfd, (const struct sockaddr *) &server_addr, sizeof(server_addr)) < 0 ) {
		printf("error in binding\n");
		exit(1);
	}
	//start listening for clients

	listen(socketfd,5);

	printf("Hello from server");
	return 0;
}