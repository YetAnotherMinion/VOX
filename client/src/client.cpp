#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

//OpenGL
#include <GL/gl.h>
#include <GL/glu.h>

#include <GLFW/glfw3.h>


//this project includes
#include "../inc/client_constants.h"

using namespace std;


int main(int argc, char *argv[])
{
	if(argc != 3) {
		std::cout << "Usage: " << argv[0] << " <hostname> <port>" << std::endl;
		return 0;
	}

	int portno = atoi(argv[2]);


	struct sockaddr_in server_addr,clilen,n;
	//AF_INET is IPv4 protocol
	int socketfiledescriptor = socket(AF_INET, SOCK_STREAM,0);

	cout << "hello client" << endl;

	return 0;
}
