#include "Node.h"
#pragma once

template <typename T>
class Tree
{
private:
	Node<T>* m_root_node = nullptr;

public:
	Tree<T>() {}
	~Tree() {}

	bool insert(T& data)
	{
		bool inserted = false;

		// If we don't already have a root node, insert this as the root node.
		if (m_root_node == nullptr)
		{
			m_root_node = new Node<T>(nullptr, data);
			inserted = true;
			return inserted;
		}

		// Start at the root...
		Node<T>* current_node = m_root_node;

		while (inserted == false)
		{
			// Traverse down to the left side of current node if data is smaller than the current node.
			if (data < *current_node->m_data)
			{
				// ...If there is already something on the left side of current node, change current node to the left node.
				if (current_node->m_left != nullptr)
				{
					current_node = current_node->m_left;
				}
				// Otherwise insert a new node with data if there isn't a left node down from the current node.
				else
				{
					current_node->m_left = new Node<T>(current_node, data);
					inserted = true;
				}
			}
			// Traverse down to the right side of current node if data is larger than the current node.
			else
			{
				// ...If there is already something on the right side of current node, change current node to the right node.
				if (current_node->m_right != nullptr)
				{
					current_node = current_node->m_right;
				}
				// Otherwise insert a new node with data if there isn't a right node down from the current node.
				else
				{
					current_node->m_right = new Node<T>(current_node, data);
					inserted = true;
				}
			}
		}
		return inserted;
	}

	bool find(T& data)
	{
		Node<T>* current_node = m_root_node;

		bool found = false;

		while (!found)
		{
			if (current_node != nullptr)
			{
				if (data < *current_node->m_data)
				{ current_node = current_node->m_left; }
				else if (data > *current_node->m_data)
				{ current_node = current_node->m_right; }
				else 
				{ found = true; }
			}
			else
			{
				return found;
			}
		}

		return found;
	}
};