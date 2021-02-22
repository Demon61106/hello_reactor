#include "ServerSocket.h"

#include <iostream>


int main(int argc, char *argv[])
{
	ServerSocket sever;
	sever.Run("127.0.0.1", 2021);
	std::cout << "Hello world!2" << std::endl;
}