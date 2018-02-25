#pragma once

namespace mstd
{
	template <typename T>
	class LinkedList;
}

class LinkedListTest
{
private:
	mstd::LinkedList<int>* m_list;
public:
	explicit LinkedListTest(const int lenght = 10);
	~LinkedListTest();
	void Run();
	void Print();
	void PrintReverse();
};
