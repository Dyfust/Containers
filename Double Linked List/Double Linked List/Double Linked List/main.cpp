#include "LinkedList.h"

// TESTING GROUND.
int main()
{
	LinkedList<int> list;

	Node<int>* start = nullptr;

	list.push_back(10);

	start = list.begin();

	return 0;
}