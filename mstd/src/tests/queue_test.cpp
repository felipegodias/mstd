#include "queue_test.h"
#include "../queue.hpp"
#include <stdio.h>

QueueTest::QueueTest() : m_queue(new mstd::Queue<int>())
{
    for (int i = 0; i < 10; i++)
    {
        m_queue->Enqueue(i);
    }
}

QueueTest::~QueueTest()
{
    delete m_queue;
}

void QueueTest::Run()
{
    const int count = m_queue->GetCount();
    printf_s("Count: %d\n", count);
    const int val = m_queue->Peek();
    printf_s("First: %d\n", val);

    while (m_queue->GetCount() != 0)
    {
        const int rval = m_queue->Dequeue();
        printf_s("%d, ", rval);
    }
}
