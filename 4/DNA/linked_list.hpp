// Куприянов Кирилл БПИ151

#include <stdexcept>
#include "linked_list.h"

namespace xi
{

    using std::out_of_range;


    template<typename T>
    LinkedList<T>::LinkedList()
    {
        _preHead = new Node<T>;
        _preHead->next = nullptr;
    }

    template<typename T>
    LinkedList<T>::~LinkedList()
    {
        Node<T> *temp = _preHead;
        for (; temp->next != nullptr;)
        {
            Node<T> *tmp = temp->next;
            delete temp;
            temp = tmp;
        }
        delete temp;
        temp = nullptr;
    }


    template<typename T>
    Node<T> *LinkedList<T>::getPreHead()
    {
        return _preHead;
    }

    template<typename T>
    T &LinkedList<T>::operator[](int i)
    {
        if (i >= 0 && _preHead->next != nullptr)
        {
            Node<T> *temp = _preHead;
            for (; i >= 0; --i)
            {
                temp = temp->next;
                if (temp == nullptr)
                    throw out_of_range("index out of range exception");
            }
            return temp->value;
        } else
            throw out_of_range("i shoud be non negative");
    }

    template<typename T>
    int LinkedList<T>::size()
    {
        int i = 0;
        Node<T> *temp = _preHead;
        for (; (*temp).next; ++i)
            temp = (*temp).next;
        return i;
    }


    template<typename T>
    void LinkedList<T>::addElementToEnd(T &value)
    {
        Node<T> *tmp = new Node<T>();
        tmp->value = value;
        Node<T> *end_node = _preHead;
        while (end_node->next)
            end_node = end_node->next;
        Node<T> *end = end_node;
        end->next = tmp;
    }

    template<typename T>
    void LinkedList<T>::deleteNodes(Node<T> *pNodeBefore, Node<T> *pNodeLast)
    {
        while (pNodeBefore->next != pNodeLast)
            deleteNextNode(pNodeBefore);
        deleteNextNode(pNodeBefore);
    }

    template<typename T>
    void LinkedList<T>::deleteNextNode(Node<T> *pNodeBefore)
    {
        Node<T> *tmp = pNodeBefore->next;
        pNodeBefore->next = pNodeBefore->next->next;
        delete tmp;
    }

    template<typename T>
    void LinkedList<T>::moveNodesToEnd(Node<T> *pNodeBefore, Node<T> *pNodeLast)
    {
        Node<T> *last_node = _preHead;
        while (last_node->next)
            last_node = last_node->next;
        moveNodesAfter(last_node, pNodeBefore, pNodeLast);
    }


    template<typename T>
    void LinkedList<T>::moveNodeToEnd(Node<T> *pNodeBefore)
    {
        Node<T> *last_node = _preHead;
        while (last_node->next)
            last_node = last_node->next;
        moveNodeAfter(last_node, pNodeBefore);
    }


    template<typename T>
    void LinkedList<T>::moveNodesAfter(Node<T> *pNode, Node<T> *pNodeBefore, Node<T> *pNodeLast)
    {
        Node<T> *t1 = pNode->next;
        pNode->next = pNodeBefore->next;
        Node<T> *t2 = pNodeLast->next;
        pNodeBefore->next = t2;
        pNodeLast->next = t1;
    }

    template<typename T>
    void LinkedList<T>::moveNodeAfter(Node<T> *pNode, Node<T> *pNodeBefore)
    {
        Node<T> *temp = pNodeBefore->next;
        pNodeBefore->next = (*pNodeBefore->next).next;
        Node<T> *node2 = temp;
        Node<T> *curr_tail = pNode->next;
        pNode->next = node2;
        node2->next = curr_tail;
    }

    template<typename T>
    LinkedList<T>::LinkedList(const LinkedList<T> &other)
    {
        _preHead = new Node<T>();
        Node<T> *current = other._preHead->next;
        for (; current != nullptr;)
        {
            addElementToEnd(current->value);
            current = current->next;
        }
    }

    template<typename T>
    LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
    {
        if (this != &other)
        {
            Node<T> *last_node = _preHead;
            while (last_node->next)
                last_node = last_node->next;

            if (_preHead->next != nullptr)
                deleteNodes(_preHead, last_node);

            Node<T> *temp = (*other._preHead).next;
            for (; temp != nullptr;)
            {
                addElementToEnd(temp->value);
                temp = temp->next;
            }
        }
        return *this;

    }

}


// EOF
