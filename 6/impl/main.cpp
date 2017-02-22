#include <iostream>
#include "BidiLinkedList.h"
#include <stdexcept>

int main()
{
    BidiLinkedList<int> *bll = new BidiLinkedList<int>();
    bll->appendEl(5);
    bll->appendEl(3);
    bll->appendEl(7);
    bll->appendEl(4);
    size_t s = bll->getSize();
    BidiLinkedList<int>::Node *node = new BidiLinkedList<int>::Node(12);
    bll->insertNodeAfter(bll->getHeadNode(), node);
    if (s + 1 != bll->getSize())
        throw std::exception();

//    bll->cutNode(node);
    BidiLinkedList<int>::Node *seven = bll->findFirst(bll->getHeadNode(), 7);
    BidiLinkedList<int>::Node *twelve = bll->findFirst(bll->getHeadNode(), 12);
    if (twelve != nullptr && seven->getValue() != 7)
        throw std::exception();

    bll->insertNodeBefore(node, seven);


    delete bll;
    bll = nullptr;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}