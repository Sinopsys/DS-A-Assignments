//
// Created by kirill on 08.02.17.
//

#include "linked_list.h"

int main()
{
    using namespace xi;
    int data[] = {0, 1, 2, 3};
    LinkedList<int> sa;
    sa.addElementToEnd(data[0]);
    sa.addElementToEnd(data[1]);
    sa.addElementToEnd(data[2]);
    sa.addElementToEnd(data[3]);

    LinkedList<int> sb{sa};
    sb.addElementToEnd(data[0]);

    return 0;
}