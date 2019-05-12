#include "List.h"

int main()
{
	List<int>* ages = new List<int>(5);

	for (size_t i = 0; i < 5; i++)
	{
		ages->Push(i);
	}

	int age = 1500;
	int age1 = 2000;
	int age2 = 3000;

	ages->AddAtIndex(age, 0);
	ages->AddAtIndex(age1, 0);
	ages->AddAtIndex(age2, 0);

	return 0;
}