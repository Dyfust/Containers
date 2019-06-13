#pragma once

#include <functional>
namespace HashFunctions
{
	typedef std::function< unsigned int(const char*, unsigned int)> Hash_Func;

	unsigned int basic_hash(const char* a_data, unsigned int a_length);
	unsigned int BKDR_hash(const char* a_data, unsigned int a_length);
	unsigned int ELF_hash(const char* a_data, unsigned int a_length);

	// a helper to access a default hash function
	static Hash_Func defaultFunc = ELF_hash;
}