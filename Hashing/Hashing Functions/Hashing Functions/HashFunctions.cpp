#include "HashFunctions.h"

unsigned int HashFunctions::basic_hash(const char* a_data, unsigned int a_length)
{
	int hash = 0;

	for (int i = 0; i < a_length; i++)
	{
		hash += a_data[i];
	}

	return hash;
}

unsigned int HashFunctions::BKDR_hash(const char* a_data, unsigned int a_length)
{
	int hash = 0;

	for (int i = 0; i < a_length; i++)
	{
		hash = (hash * 1313) + a_data[i];
	}


	return (hash & 0x7FFFFFFF);
}

unsigned int HashFunctions::ELF_hash(const char* a_data, unsigned int a_length)
{
	int hash = 0, x = 0;

	for (int i = 0; i < a_length; i++)
	{
		hash = (hash << 4) + a_data[i];
		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF);
}