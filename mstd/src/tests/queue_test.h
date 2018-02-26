#pragma once

namespace mstd
{
    template <typename T>
    class Queue;
}

class QueueTest
{
private:
    mstd::Queue<int>* m_queue;
public:
    explicit QueueTest();
    ~QueueTest();

    void Run();
    void Print();
};
