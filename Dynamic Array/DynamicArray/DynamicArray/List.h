#pragma once
template <typename T>
class List
{
private:
	T* m_data = nullptr;
	int m_capacity = 10;
	int m_count = 0;

	void Expand()
	{
		m_capacity *= 2;
		T* new_array = new T[m_capacity];

		for (size_t index = 0; index < m_count; index++)
		{
			new_array[index] = m_data[index];
		}

		delete[] m_data;
		m_data = new_array;
		new_array = nullptr;
	}

public:
	T& operator[](const size_t index)
	{
		return m_data[index];
	}

	List& operator=(List& a_list) {
		if (&a_list == this)
		{
			return *this;
		}

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

	List(int a_default_capacity)
	{
		m_capacity = a_default_capacity;
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

	/*!
		\brief Pushes obj to the end of the list
		\param a_obj value being pushed to the list
	*/
	void Push(const T& obj)
	{
		m_data[m_count] = obj;
		m_count++;
	}

	/*!
		\brief Pops the last obj off the list
	*/
	void Pop()
	{
		m_count--;
	}

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
			m_data[(m_count - 1) - i] = m_data[(m_count - 2) - i];

			if (i == 0)
				m_data[i] = obj;
		}
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
		int length = (m_count - 1) - index;

		for (size_t i = 0; i < length; i++)
		{
			m_data[i] = m_data[i + 1];
		}
	}

	const int get_count() const
	{
		return m_count;
	}
};