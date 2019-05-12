#include <iostream>
#include "Tree.h"

int main()
{
	Tree<int> m_bst;

	int num = 10;
	int num2 = 9;
	int num3 = 15;
	int num4 = 21;
	int num5 = 18;

	bool found = true;

	m_bst.insert(num);
	m_bst.insert(num2);
	m_bst.insert(num3);
	m_bst.insert(num4);

	found = m_bst.find(num5);

	return 0;
}