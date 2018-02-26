#include "linked_list_test.h"
#include "../linked_list.hpp"
#include <stdio.h>

LinkedListTest::LinkedListTest(const int lenght) : m_list(new mstd::LinkedList<int>())
{
    for (int i = 0; i < lenght; i++)
    {
        m_list->AddLast(i);
    }
}

LinkedListTest::~LinkedListTest()
{
    delete m_list;
}

void LinkedListTest::Run()
{
    m_list->Remove(0);
    m_list->Remove(9);
    m_list->Remove(1);
    m_list->Remove(8);

    Print();
    PrintReverse();

    printf_s("Contains 2: %d", m_list->Contains(2));
    printf_s("\n");
    printf_s("Contains 7: %d", m_list->Contains(7));
    printf_s("\n");
    printf_s("Count: %d", m_list->GetCount());
}

void LinkedListTest::Print()
{
    printf_s("Print: ");
    auto it = m_list->GetFirst();
    while (it != nullptr)
    {
        printf_s("%d, ", it->GetData());
        it = it->GetNext();
    }
    printf_s("\n");
}

void LinkedListTest::PrintReverse()
{
    printf_s("Print Reverse: ");
    auto it = m_list->GetLast();
    while (it != nullptr)
    {
        printf_s("%d, ", it->GetData());
        it = it->GetPrevious();
    }
    printf_s("\n");
}
