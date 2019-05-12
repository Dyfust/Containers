#pragma once

template <typename T>
class Node
{
public:
	T* m_data = nullptr;

	Node<T>* m_parent = nullptr;

	Node<T>* m_left = nullptr;
	Node<T>* m_right = nullptr;

	Node<T>(Node<T>* a_parent, T& a_data)
	{
		m_parent = a_parent;
		m_data = &a_data;
	}

	Node<T>() = delete;

	~Node() {}
};

