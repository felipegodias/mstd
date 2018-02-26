#pragma once

#include "exception.h"

namespace mstd
{
    template <typename T>
    struct QueueNode
    {
    private:
        QueueNode<T>* m_next;
        const T m_data;

    public:
        QueueNode() = delete;
        QueueNode(const QueueNode&) = delete;

    private:
        explicit QueueNode(const T& data) : m_next(nullptr), m_data(data)
        {
        }

        friend void Queue<T>::Enqueue(const T& data);
        friend T Queue<T>::Dequeue();
        friend T Queue<T>::Peek() const;
        friend void Queue<T>::Clear();
        friend bool Queue<T>::Contains(const T& data) const;
    };

    template <typename T>
    class Queue
    {
    private:
        QueueNode<T>* m_head;
        QueueNode<T>* m_tail;
        unsigned int m_count;
    public:
        explicit Queue() : m_head(nullptr), m_tail(nullptr), m_count(0)
        {
        }

        ~Queue()
        {
            Clear();
        }

        unsigned int GetCount() const
        {
            return m_count;
        }

        void Enqueue(const T& data)
        {
            QueueNode<T>* new_node = new QueueNode<T>(data);
            if (m_head == nullptr)
            {
                m_head = new_node;
            }
            if (m_tail == nullptr)
            {
                m_tail = new_node;
            }
            else
            {
                m_tail->m_next = new_node;
                m_tail = new_node;
            }
            m_count++;
        }

        T Dequeue()
        {
            if (m_head == nullptr)
            {
                throw MSTD_INVALID_OPERATION_EXCEPTION;
            }
            QueueNode<T>* node_to_delete = m_head;
            T out = m_head->m_data;
            m_head = m_head->m_next;
            m_count--;
            delete node_to_delete;
            return out;
        }

        T Peek() const
        {
            if (m_head == nullptr)
            {
                throw MSTD_INVALID_OPERATION_EXCEPTION;
            }
            return m_head->m_data;
        }

        bool Contains(const T& data) const
        {
            QueueNode<T>* it = m_head;
            while (it != nullptr)
            {
                if (it->m_data == data)
                {
                    return true;
                }
                it = it->m_next;
            }
            return false;
        }

        void Clear()
        {
            QueueNode<T>* it = m_head;
            while (it != nullptr)
            {
                QueueNode<T>* next = it->m_next;
                delete it;
                it = next;
            }
        }
    };
}
