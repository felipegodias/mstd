#include <stdio.h>
#include "linked_list.hpp"
#include "tests/linked_list_test.h"
#include "tests/queue_test.h"

int main(int argc, char* argv[])
{
    {
        QueueTest queue_test = QueueTest();
        queue_test.Run();
    }
    /*
    LinkedListTest linked_list_test = LinkedListTest(10);
    linked_list_test.Run();
    */
    int cin = 0;
    scanf_s("%d", &cin);
    return 0;
}
