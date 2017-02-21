#include <iostream>
#include "BidiLinkedList.h"
int main()
{
    BidiLinkedList<int> bll;
    bll.appendEl(1);
    bll.appendEl(2);
    bll.appendEl(3);
    bll.appendEl(4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}