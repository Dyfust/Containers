#pragma once

template <typename T>
class Node
{
private:
	T* m_data = nullptr;

public:
	Node<T>* m_parent = nullptr;

	Node<T>* m_left = nullptr;
	Node<T>* m_right = nullptr;

	Node<T>(T& a_data)
	{
		m_data = &a_data;
	}

	Node<T>() = delete;

	~Node() {}
};

