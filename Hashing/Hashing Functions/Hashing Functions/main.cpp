#include <iostream>
#include "HashFunctions.h"

int main()
{
	const unsigned int size = 15;
	char* test_string = new char[size] { "I am a baddie!"};

	std::cout << "Basic Hash of " << test_string << std::endl;
	std::cout << HashFunctions::basic_hash(test_string, size) << std::endl;

	std::cout << "BKDR Hash of " << test_string << std::endl;
	std::cout << HashFunctions::BKDR_hash(test_string, size) << std::endl;

	std::cout << "ELF Hash of " << test_string << std::endl;
	std::cout << HashFunctions::ELF_hash(test_string, size) << std::endl;

	return 0;
}