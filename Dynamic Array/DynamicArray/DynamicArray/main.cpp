#include "List.h"
#include "crtdbg.h"
#include <ctime>
#include <iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(0));	

	List<int> items = List<int>();

	for (size_t index = 0; index < 10; index++)
	{
		items.Push(rand());
	}

	items.sort();

	items.RemoveAtIndex(0);

	return 0;
}