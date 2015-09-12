#include <iostream>
#include <sys/types.h>
#include <stdlib.h>
/*gives you bzero */
#include <string.h>
/*Networking */
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
/*OpenGL*/
#include <GL/gl.h>
#include <GL/glu.h>

//#include <GLFW/glfw3.h>


/*this project includes*/
#include "../inc/client_constants.h"



int main(int argc, char *argv[])
{
	if(argc != 3) {
		std::cout << "Usage: " << argv[0] << " <hostname> <port>" << std::endl;
		return 0;
	}

	int n; /*store the number of bytes transmitted */
	int socketfd;
	char buffer[256];
	struct addrinfo hints;
	struct addrinfo* servinfo;

	bzero((char*)&hints, sizeof hints);
	hints.ai_family = AF_UNSPEC; /*could use AF_INET or AF_INET6*/
	hints.ai_socktype = SOCK_STREAM;

	n = getaddrinfo(argv[1], argv[2], &hints, &servinfo);
	if(n != 0) {
		fprintf(stderr, "getaddrinfo failed\n" );
	}
	/*AF_INET is IPv4 protocol
	Creating the the socket point*/
	socketfd = socket(servinfo->ai_family, servinfo->ai_socktype,servinfo->ai_protocol);
	if(socketfd < 0) {
		perror("ERROR opening socket\n");
		exit(1);
	}

	n = connect(socketfd, servinfo->ai_addr, servinfo->ai_addrlen);

	if(n < 0){
		perror("ERROR on connect");
		exit(1);
	} else {
		printf("Connected!\n");
	}

	char* msg = "Message from client!";
	int len = strlen(msg);

	n = send(socketfd, msg, len, 0);

	if(n < 0) {
		perror("ERROR on send\n");
		exit(1);
	}

	n = recv(socketfd, (void*) buffer, 255, 0);
	if(n < 0) {
		fprintf(stderr, "ERROR on recv\n");
		exit(1);
	} else if(n == 0) {
		printf("Conncection closed\n");
	} else {
		printf("The message was: \n%s\n",buffer );
	}

	n = close(socketfd);

	std::cout << "hello client" << std::endl;

	return 0;
}
