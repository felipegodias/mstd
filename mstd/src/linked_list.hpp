#pragma once

namespace mstd
{
	template <typename T>
	class LinkedList;

	template <typename T>
	struct LinkedListNode
	{
	private:
		const LinkedList<T>* m_list;
		LinkedListNode<T>* m_next;
		LinkedListNode<T>* m_previous;
		const T m_data;

	public:
		LinkedListNode() = delete;
		LinkedListNode(const LinkedListNode<T>&) = delete;

		LinkedListNode<T>* GetNext() const
		{
			return m_next;
		}

		LinkedListNode<T>* GetPrevious() const
		{
			return m_previous;
		}

		T GetData() const
		{
			return m_data;
		}

	private:
		explicit LinkedListNode(const LinkedList<T>* list, const T& data) : m_list(list), m_next(nullptr),
		                                                                    m_previous(nullptr), m_data(data)
		{
		}

		friend void LinkedList<T>::AddFirst(const T data);
		friend void LinkedList<T>::AddAfter(LinkedListNode<T>* node, const T data);
		friend void LinkedList<T>::AddBefore(LinkedListNode<T>* node, const T data);
		friend bool LinkedList<T>::Remove(LinkedListNode<T>* node);
	};

	template <typename T>
	class LinkedList
	{
	private:
		LinkedListNode<T>* m_head;
		LinkedListNode<T>* m_tail;
		unsigned int m_count;

	public:
		explicit LinkedList()
		{
			m_count = 0;
		}

		~LinkedList()
		{
			LinkedListNode<T>* it = m_head;
			while (it != nullptr)
			{
				LinkedListNode<T>* next = it->GetNext();
				delete it;
				it = next;
			}
		}

		LinkedListNode<T>* GetFirst() const
		{
			return m_head;
		}

		LinkedListNode<T>* GetLast() const
		{
			return m_tail;
		}

		unsigned int GetCount() const
		{
			return m_count;
		}

		void AddFirst(const T data)
		{
			if (m_head == nullptr)
			{
				m_head = new LinkedListNode<T>(this, data);
				m_tail = m_head;
				m_count++;
			}
			else
			{
				AddBefore(m_head, data);
			}
		}

		void AddLast(const T data)
		{
			if (m_head == nullptr)
			{
				AddFirst(data);
			}
			else
			{
				AddAfter(m_tail, data);
			}
		}

		void AddAfter(LinkedListNode<T>* node, const T data)
		{
			if (node == nullptr || node->m_list != this)
			{
				return;
			}

			LinkedListNode<T>* new_node = new LinkedListNode<T>(this, data);
			new_node->m_next = node->m_next;
			new_node->m_previous = node;
			if (node->m_next != nullptr)
			{
				node->m_next->m_previous = new_node;
			}
			node->m_next = new_node;

			if (node == m_tail)
			{
				m_tail = new_node;
			}
			m_count++;
		}

		void AddBefore(LinkedListNode<T>* node, const T data)
		{
			if (node == nullptr || node->m_list != this)
			{
				return;
			}

			LinkedListNode<T>* new_node = new LinkedListNode<T>(this, data);
			new_node->m_next = node;
			new_node->m_previous = node->m_previous;
			if (node->m_previous != nullptr)
			{
				node->m_previous->m_next = new_node;
			}
			node->m_previous = new_node;

			if (node == m_head)
			{
				m_head = new_node;
			}
			m_count++;
		}

		void AddAt(const unsigned int index, T data)
		{
			
			if (m_count == 0 || index == 0)
			{
				this->AddFirst(data);
			}
			else if(m_count <= index)
			{
				this->AddLast(data);
			}
			else
			{
				int i = 1;
				LinkedListNode<T>* it = m_head;
				while (it != nullptr)
				{
					if (i == index)
					{
						this->AddBefore(it, data);
						break;
					}
					i++;
					it = it->GetNext();
				}
			}
		}

		bool Remove(const T data)
		{
			LinkedListNode<T>* it = m_head;
			while (it != nullptr)
			{
				if (it->GetData() == data)
				{
					return Remove(it);
				}
				it = it->GetNext();
			}
			return false;
		}

		bool Remove(LinkedListNode<T>* node)
		{
			if (node == nullptr || node->m_list != this)
			{
				return false;
			}

			if (node == m_head)
			{
				if (node == m_tail)
				{
					m_head = nullptr;
					m_tail = nullptr;
				}
				else
				{
					m_head = node->m_next;
					m_head->m_previous = nullptr;
				}
			}
			else if (node == m_tail)
			{
				m_tail = node->m_previous;
				m_tail->m_next = nullptr;
			}
			else
			{
				node->m_previous->m_next = node->m_next;
				node->m_next->m_previous = node->m_previous;
			}

			delete node;
			m_count--;
			return true;
		}

		bool RemoveFirst()
		{
			return Remove(m_head);
		}

		bool RemoveLast()
		{
			return Remove(m_tail);
		}

		bool RemoveAt(const unsigned int index)
		{
			if (m_count == 0 || index >= m_count)
			{
				return false;
			}

			int i = 1;
			LinkedListNode<T>* it = m_head;
			while (it != nullptr)
			{
				if (i == index)
				{
					return Remove(it);
				}
				i++;
				it = it->GetNext();
			}

			return false;
		}

		bool Contains(const T data) const
		{
			return Find(data) != nullptr;
		}

		LinkedListNode<T>* Find(const T data) const
		{
			LinkedListNode<T>* it = m_head;
			while (it != nullptr)
			{
				if (it->GetData() == data)
				{
					return it;
				}
				it = it->GetNext();
			}
			return nullptr;
		}

		LinkedListNode<T>* FindLast(const T data) const
		{
			LinkedListNode<T>* it = m_tail;
			while (it != nullptr)
			{
				if (it->GetData() == data)
				{
					return it;
				}
				it = it->GetPrevious();
			}
			return nullptr;
		}

		void Clear()
		{
			LinkedListNode<T>* it = m_head;
			while (it != nullptr)
			{
				LinkedListNode<T>* next = it->GetNext();
				delete it;
				it = next;
			}
			m_head = nullptr;
			m_tail = nullptr;
			m_count = 0;
		}

	};
}
