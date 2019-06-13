#pragma once
#include "assert.h"

template <typename T>
class Node
{
public:
	T m_data;

	Node<T>* m_previous;
	Node<T>* m_next;
};

template <typename T>
class LinkedList
{
private:
	size_t m_count;
public:
	// Sentinel nodes.
	Node<T>* m_startNode = nullptr;
	Node<T>* m_endNode = nullptr;

	// Constructors
	LinkedList<T>()
	{
		// Establish the sentinel nodes and link them.
		m_startNode = new Node<T>();
		m_endNode = new Node<T>();

		m_startNode->m_next = m_endNode;
		m_endNode->m_previous = m_startNode;

		m_count = 0;
	}

	// Destructors
	~LinkedList()
	{
		// Clear the linked list
		clear();

		// Delete sentinel nodes.
		delete m_startNode;
		m_startNode = nullptr;
		delete m_endNode;
		m_endNode = nullptr;
	}

	/*!
		\brief Adds an item to the end.
		\param a_data The item that is being added.
	*/
	void push_back(const T& a_data)
	{
		// Create a new node and add it to the back.
		Node<T>* current = new Node<T>();
		current->m_data = a_data;

		m_endNode->m_previous->m_next = current;
		current->m_previous = m_endNode->m_previous;
		m_endNode->m_previous = current;

		m_count++;
	}

	/*!
		\brief Adds an item to the front.
		\param a_data The item that is being added.
	*/
	void push_front(const T& a_data)
	{
		// Create a new node and add it to the front.
		Node<T>* current = new Node<T>();
		current->m_data = a_data;

		current->m_next = m_startNode->m_next;
		m_startNode->m_next->m_previous = current;
		current->m_previous = m_startNode;
		m_startNode->m_next = current;

		m_count++;
	}

	/*!
		\brief Insert an item at the specified location.
		\param a_data The item being inserted.
		\param a_index Location of insertion.
	*/
	void insert(const T& a_data, const int a_index)
	{
		Node<T>* current = m_startNode->m_next;
		int counter = 0;

		// Traverse to the location.
		while (counter < a_index && current != m_endNode)
		{
			++counter;
			current = current->m_next;
		}

		Node<T>* new_node = new Node<T>;
		new_node->m_data = a_data;

		new_node->m_next = current;
		current->m_previous = current->m_previous;
		current->m_previous = new_node;
		new_node->m_previous->m_next = new_node;

		m_count++;
	}


	/*!
		\brief Removes all nodes with the matching value.
		\param a_value the value to match with nodes.
	*/
	void remove(const T a_value)
	{
		Node<T>* current = m_startNode->m_next;

		// Traverse through the linked.
		while (current != m_endNode)
		{
			// Delete all nodes with a_value.
			if (current->m_data == a_value)
			{
				current = remove(current);
			}

			current = current->m_next;
		}

		m_count--;
	}

	Node<T>* remove(Node<T>* a_remove_node)
	{
		Node<T>* next_node = a_remove_node->m_next;
		Node<T>* previous_node = a_remove_node->m_previous;

		// Check that the node is one that can be removed.
		if (a_remove_node != m_startNode && a_remove_node != m_endNode)
		{
			// List in preparation for deletion
			next_node->m_previous = a_remove_node->m_previous;
			previous_node->m_next = next_node;

			// Deallocate the node from memory.
			delete a_remove_node;
			a_remove_node = nullptr;

			m_count--;
		}

		// Return the node that was next to the deleted node.
		return next_node;
	}

	/*!
		\brief Removes the last valid node in the linked list.
		\return Returns a bool which specifies wether the removal was successful.
	*/
	bool pop_back()
	{
		Node<T>* current = m_endNode->m_previous;

		// Determine wether the last node is valid, remove if yes.
		if (current != m_startNode)
		{
			remove(current);
			m_count--;

			return true;
		}
		else
		{
			return false;
		}
	}

	/*!
		\brief Removes the first valid node in the linked list.
		return Returns a bool which specifies wether the removal was successful.
	*/
	bool pop_front()
	{
		Node<T>* current = m_startNode->m_next;

		// Determine wether the first node is valid, remove is yes.
		if (current != m_endNode)
		{
			remove(current);
			m_count--;

			return true;
		}
		else 
		{
			return false;
		}
	}

	/*!
		\brief Removes all nodes in the linked list;
	*/
	void clear()
	{
		Node<T>* current = m_startNode->m_next;

		// Traverse through the list and remove all the valid nodes.
		while (current != m_endNode)
		{
			Node<T>* next = current->m_next;
			delete current;
			current = next;
		}

		// Link the start to the end.
		m_startNode->m_next = m_endNode;
		m_endNode->m_previous = m_startNode;

		// Reset the count.
		m_count = 0;
	}

	// ---Getters---

	/*!
		\brief Returns an iterator to the first valid node.
	*/
	Node<T>* begin()
	{
		assert(m_startNode->m_next != m_endNode && "There are no valid nodes!");
		return m_startNode->m_next;
	}

	/*!
		\brief Returns an iterator to the last valid node.
	*/
	Node<T>* end()
	{
		assert(m_endNode->m_previous != m_startNode && "There are no valid nodes!");
		return m_endNode->m_previous;
	}

	/*!
		\brief Returns the value of the first valid node.
	*/
	T first()
	{
		assert(m_startNode->m_next != m_endNode && "There are no valid nodes!");
		return m_startNode->m_next->m_data;
	}

	/*!
		\brief Returns the value of the last valid node.
	*/
	T last()
	{
		assert(m_endNode->m_previous != m_startNode && "There are no valid nodes!");
		return m_endNode->m_previous->m_data;
	}

	/*!
	\brief Return the amount of elements in the linked list.
*/
	int get_count()
	{
		return m_count;
	}

	/*!
		\brief Checks if the linked_list is empty
	*/
	bool is_empty()
	{
		return m_startNode->m_next == m_endNode;
	}
};