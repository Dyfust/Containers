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

		if (m_root_node == nullptr)
		{
			m_root_node = new Node<T>(data);
			inserted = true;
		}
		else
		{
			Node<T>* current_node = m_root_node;

			while (inserted == false) 
			{
				if (data < current_node->m_data)
				{
				 
				}
			}
		}

		return inserted;
	}
};																					  		  