#include <iostream>
#include "Tree.h"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Tree<int> m_bst;

	int num = 10;
	int num2 = 9;
	int num3 = 15;
	int num4 = 21;
	int num5 = 13;
	int num6 = 24;

	bool found = true;

	m_bst.insert(num);
	m_bst.insert(num2);
	m_bst.insert(num3);
	m_bst.insert(num4);
	m_bst.insert(num5);
	m_bst.insert(num6);

	found = m_bst.find(num5);

	m_bst.remove(num3);

	return 0;
}