#include "List.h"

int main()
{
	List<int>* ages = new List<int>(10);

	List<int>* ids = new List<int>(20);

	for (size_t i = 0; i < 10; i++)
	{
		ages->Push(i);
	}

	for (size_t i = 0; i < 20; i++)
	{
		ids->Push(i);
	}

	*ages = *ids;

	ids->Push(21);

	return 0;
}