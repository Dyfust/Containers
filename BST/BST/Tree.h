#include "Node.h"
#pragma once

template <typename T>
class Tree
{
private:
	Node<T>* m_root_node = nullptr;

	void remove_leaf(Node<T>* leaf)
	{
		Node<T>* parent_node = leaf->m_parent;

		// Find and change the parent's child pointer which pointed to this leaf to nullptr before deleting the leaf.
		if (parent_node->m_left == leaf)
		{
			parent_node->m_left = nullptr;
		}
		else
		{
			parent_node->m_right = nullptr;
		}

		delete leaf;
	}

	void remove_node_with_one_child(Node<T>* node, Node<T>* child)
	{
		Node<T>* parent_node = node->m_parent;
		child->m_parent = parent_node;

		// Find and change the parent's child pointer which pointed to this node to the node's child before deleting the node.
		if (parent_node->m_left == node)
		{
			parent_node->m_left = child;
		}
		else if (parent_node->m_right == node)
		{
			parent_node->m_right = child;
		}

		delete node;
	}

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
			// Traverse down the tree till the node is found or there's no nodes.
			if (current_node != nullptr)
			{
				// Go down to the tree to the left if the data is smaller than the node we're currently inspecting.
				if (data < *current_node->m_data)
				{ current_node = current_node->m_left; }
				// Go down to the right if it's bigger.
				else if (data > *current_node->m_data)
				{ current_node = current_node->m_right; }
				// Otherwise change "found" to true so we can return out of this function in the next iteration.
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

	bool remove(const T& data)
	{
		Node<T>* target_node = m_root_node;
		bool found = false;

		// Find the node & point to it. Return false if the node cannot be found.
		while (!found)
		{
			if (target_node != nullptr)
			{
				if (data < *target_node->m_data)
				{
					target_node = target_node->m_left;
				}
				else if (data > * target_node->m_data)
				{
					target_node = target_node->m_right;
				}
				else
				{
					found = true;
				}
			}
			else
			{
				return found;
			}
		}

		// The code that actually deletes the node.
		bool removed = false;

		// Situation #1: target node has no children.
		if (target_node->m_left == nullptr && target_node->m_right == nullptr) 
		{
			remove_leaf(target_node);
			removed = true;
		}
		// Situation #2: target node has one child.
		else if (target_node->m_left != nullptr && target_node->m_right == nullptr) 
		{
			remove_node_with_one_child(target_node, target_node->m_left);
			removed = true;
		}
		else if (target_node->m_left == nullptr && target_node->m_right != nullptr)
		{
			remove_node_with_one_child(target_node, target_node->m_right);
			removed = true;
		}
		// Siutation #3: target node has 2 children.
		else
		{
			// Find the smallest node that's bigger than the node that's being deleted.
			Node<T>* node_to_swap_with = target_node->m_right;

			while (node_to_swap_with->m_left != nullptr) 
			{
				node_to_swap_with = node_to_swap_with->m_left;
			}

			// Swap the data in them around.
			target_node->m_data = node_to_swap_with->m_data;

			// Point the target_node pointer to the node we just made the swap with and delete that instead.
			target_node = node_to_swap_with;

			// Situation #1: noo children.
			if (target_node->m_left == nullptr && target_node->m_right == nullptr)
			{
				remove_leaf(target_node);
			}
			// Situation #2: 1 child.
			else if (target_node->m_left != nullptr && target_node->m_right == nullptr)
			{
				remove_node_with_one_child(target_node, target_node->m_left);
			}
			else if (target_node->m_left == nullptr && target_node->m_right != nullptr)
			{
				remove_node_with_one_child(target_node, target_node->m_right);
			}

			removed = true;
		}

		return removed;
	}
};