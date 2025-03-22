#include <iostream>

int main() 
{
	std::string brainMessage = "HI THIS IS BRAIN";

	std::string* stringPTR = &brainMessage;

	std::string& stringREF = brainMessage;

	std::cout << "Memory Addresses:" << std::endl;
	std::cout << "Address of brainMessage  : " << &brainMessage << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "\nValues:" << std::endl;
	std::cout << "Value of brainMessage  : " << brainMessage << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF: " << stringREF << std::endl;

    return 0;
}

