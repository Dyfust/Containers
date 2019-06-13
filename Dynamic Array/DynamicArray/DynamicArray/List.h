#pragma once
template <typename T>
class List
{
private:
	T* m_data = nullptr;
	int m_capacity = 10;
	int m_initial_capacity = 10;
	int m_count = 0;

	/*!
		\brief Expands the array by twice it's size.
	*/
	void Expand()
	{
		// Increase the capacity.
		m_capacity *= 2;

		// Make a new array with the new capacity & copy over everything from the current array to the new array.
		T* new_array = new T[m_capacity];

		for (size_t index = 0; index < m_count; index++)
		{
			new_array[index] = m_data[index];
		}

		// Delete the old array.
		delete[] m_data;

		m_data = new_array;
		new_array = nullptr;
	}

public:
	// ---Constructors & Destructors---
	List(int a_default_capacity)
	{
		m_initial_capacity = a_default_capacity;
		m_capacity = m_initial_capacity;
		m_count = 0;

		m_data = new T[m_capacity];
	}

	List()
	{
		m_capacity = 10;
		m_count = 0;

		m_data = new T[m_capacity];
	}

	~List()
	{
		delete[] m_data;

		m_data = nullptr;
	}

	// Subscript operator.
	T& operator[](const size_t index)
	{
		return m_data[index];
	}

	// Assignment operator.
	List& operator=(List& a_list)
	{
		if (&a_list == this)
		{
			return *this;
		}

		// Delete the array & copy over everything.

		if (m_data)
		{
			delete m_data;

			m_data = nullptr;
		}

		m_capacity = a_list.m_capacity;
		m_count = a_list.m_count;

		m_data = new T[m_capacity];

		for (size_t i = 0; i < m_count; i++)
		{

			this->m_data[i] = a_list.m_data[i];
		}

		return *this;
	}

	/*!
		\brief Pushes obj to the end of the list.
		\param obj value being pushed to the list.
	*/
	void Push(const T& obj)
	{
		m_data[m_count] = obj;
		m_count++;
	}

	/*!
		\brief Pops the last obj off the list.
	*/
	void Pop()
	{
		m_count--;
	}

	/*!
		\brief Inserts an item at the given index.
		\param obj The item to insert.
		\param index Location of insertion.
	*/
	void AddAtIndex(T& obj, int index)
	{
		m_count++;

		if (m_count >= m_capacity)
		{
			Expand();
		}

		int length = m_count - index;

		for (size_t i = 0; i < length; i++)
		{
			m_data[m_count - 1 - i] = m_data[m_count - 2 - i];
		}

		m_data[index] = obj;
	}

	/*!
		\brief Remove an element at index.
		\note Doesn't maintain the order insertion!
	*/
	void RemoveAtIndexUnsorted(int index)
	{
		T temp = m_data[m_count - 1];
		m_data[index] = temp;
		m_count--;
	}

	void RemoveAtIndex(int index)
	{
		// Determine how far away the end is from the index, so we don't loop more than we need to.
		int length = (m_count - 1) - index;

		// Move everything forward by one from the index.
		for (size_t i = 0; i < length; i++)
		{
			m_data[i] = m_data[i + 1];
		}

		m_count--;
	}
	
	// Deallocate excess allocated memory from this dynamic array.
	void trim()
	{
		// Create a new array with enough space for the amount of items in it already if there is excess space in the array.
		if (m_capacity > m_count)
		{
			m_capacity = m_count;

			T* new_data = new T[m_capacity];

			for (size_t index = 0; index < m_count; index++)
			{
				new_data[index] = m_data[index];
			}

			delete[] m_data;

			m_data = new_data;
			new_data = nullptr;
		}
	}

	// Clear the data & reset the dynamic array to it's default state.
	void clear()
	{
		// Reset the capacity to default capacity.
		m_capacity = m_initial_capacity;

		// Deallocate the array from memory and allocate a new array with the default capacity.
		delete[] m_data;
		m_data = new T[m_capacity];

		m_count = 0;
	}

	// Bubble sort.
	void sort()
	{
		bool swapped = true;

		int amount = m_count;

		while (swapped)
		{
			// If nothing has been swapped in this iteration, the dynamic array has been sorted, otherwise it hasn't.
			swapped = false;

			for (size_t index = 0; index < amount - 1; index++)
			{
				// Swap if the current data is bigger than the next data.
				if (m_data[index] > m_data[index + 1])
				{
					T temp = m_data[index];

					m_data[index] = m_data[index + 1];
					m_data[index + 1] = temp;

					// Set the swapped flag to true.
					swapped = true;
				}
			}

			amount--;
		}
	}

	const int get_count() const
	{
		return m_count;
	}
};