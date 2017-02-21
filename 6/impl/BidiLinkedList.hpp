//
// Created by kirill on 21.02.17.
//

///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Contains pseudo-implementation part of bidirectional list structure
/// template declared in the file's h-counterpart
///
/// © Sergey Shershakov 2015–2016
///
/// No part of this code can be used without an explicit permission of the author.
/// The exception is done for educational goals of the course "Algorithms and Data
/// Structures" provided by the School of Software Engineering of the Faculty
/// of Computer Science at the Higher School of Economics.
///
/// When altering code, a copyright line must be preserved.
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
//#include "BidiLinkedList.h"


//==============================================================================
// class BidiList<T>::Node
//==============================================================================


template<typename T>
typename BidiLinkedList<T>::Node *
BidiLinkedList<T>::Node::insertAfterInternal(Node *insNode)
{
    // here we use "this" keyword for enhancing the fact we deal with curent node!
    Node *afterNode = this->_next;      // an element, which was after node
    this->_next = insNode;
    afterNode->_prev = insNode;
    insNode->_next = afterNode;
    insNode->_prev = this;
    return insNode;
}

//==============================================================================
// class BidiList<T>
//==============================================================================


// следующий метод полностью реализован
template<typename T>
BidiLinkedList<T>::~BidiLinkedList()
{
    clear();
}


template<typename T>
void BidiLinkedList<T>::clear()
{
    Node *tmp = getHeadNode();
    while (tmp)
    {
        _head = _head->getNext();
        delete tmp;
        tmp = nullptr;
        tmp = _head;
    }
    invalidateSize();
}

template<typename T>
size_t BidiLinkedList<T>::getSize()
{
    if (_size == NO_SIZE)
        calculateSize();

    return _size;
}


template<typename T>
void BidiLinkedList<T>::calculateSize()
{
    Node *tmp = getHeadNode();
    size_t size = 0;
    while (tmp)
    {
        tmp = tmp->getNext();
        ++size;
    }
    _size = size;

    // !...
    // Метод необходимо реализовать целиком!
    // !...
}


template<typename T>
typename BidiLinkedList<T>::Node *BidiLinkedList<T>::getLastNode() const
{
    if (_head == nullptr)
        return nullptr;
    Node *tmp = _head;
    while (tmp->getNext())
        tmp = tmp->getNext();
    return tmp;

    // !...
    // Метод необходимо реализовать целиком!
    // !...
}


template<typename T>
typename BidiLinkedList<T>::Node *
BidiLinkedList<T>::appendEl(const T &val)
{
    Node *newNode = new Node(val);
    // inserts after last node, size if going to e invalidated there
    return insertNodeAfter(getLastNode(), newNode);
}


// следующий метод полностью реализован, на него можно смотреть, как на образец и "делать два раза ку!" (с)
// не надо изменять его, если нет желания сделать какую-то специальную супер-оптимизацию
template<typename T>
typename BidiLinkedList<T>::Node *
BidiLinkedList<T>::insertNodeAfter(Node *node, Node *insNode)
{
    if (!insNode)
        throw std::invalid_argument("`insNode` is nullptr");

    if (!node)
        node = getLastNode();

    // if last node is nullptr itself, it means that no elements in the list at all
    if (!node)
        _head = insNode;
    else
        node->insertAfterInternal(insNode);


    invalidateSize();

    return insNode;
}


// !...
// Здесь должна быть реализация метода BidiLinkedList<T>::insertNodesAfter().
// В отличие от других методов, здесь не представлен даже заголовок, поэтому придется потрудиться!
// !...
template<typename T>
void BidiLinkedList<T>::insertNodesAfter
        (BidiLinkedList::Node *node, BidiLinkedList::Node *beg, BidiLinkedList::Node *end)
{
    if (beg == nullptr || end == nullptr)
        throw std::invalid_argument("Wrong begin or end values");

    Node *next = node->_next;
    beg->_prev = node;
    node->_next = beg;
    end->_next = next;
    if (next)
        next->_prev = end;

    invalidateSize();
}




// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательствa
#ifdef IWANNAGET10POINTS


template <typename T>
typename BidiLinkedList<T>::Node*
    BidiLinkedList<T>::insertNodeBefore(Node* node, Node* insNode)
{



    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...



}


template <typename T>
void BidiLinkedList<T>::insertNodesBefore(Node* node, Node* beg, Node* end)
{
    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...

}



#endif // IWANNAGET10POINTS


template<typename T>
void BidiLinkedList<T>::cutNodes(Node *beg, Node *end)
{
    if (!beg || !end)
        throw std::invalid_argument("Either `beg` or `end` is nullptr");

    Node *next_to_end = end->getNext();
    Node *prev_to_beg = beg->getPrev();
    if (prev_to_beg && next_to_end)
    {
        prev_to_beg->_next = next_to_end;
        next_to_end->_prev = prev_to_beg;
    }
    if (_head == beg)
        if (next_to_end)
            _head = next_to_end;
        else
            _head = nullptr;
    invalidateSize();
}


template<typename T>
typename BidiLinkedList<T>::Node *
BidiLinkedList<T>::cutNode(Node *node)
{
    if (node == nullptr)
        throw std::invalid_argument("Wrong value");
    Node *next = node->getNext();
    Node *prev = node->getPrev();
    if (prev && next)
    {
        prev->_next = next;
        next->_prev = prev;
    }
    if (_head == node)
        if (next)
            _head = next;
        else
            _head = nullptr;
    invalidateSize();
    return node;
}


template<typename T>
typename BidiLinkedList<T>::Node *
BidiLinkedList<T>::findFirst(Node *startFrom, const T &val)
{
    if (!startFrom)
        return nullptr;






    // !...
    // Здесь вырезана часть кода. Ее необходимо реализовать
    // !...







    return nullptr;     // not found
}


template<typename T>
typename BidiLinkedList<T>::Node **
BidiLinkedList<T>::findAll(Node *startFrom, const T &val, int &size)
{
    if (!startFrom)
        return nullptr;

    // try not to use any standard containers. create an array only when found a first occurence
    Node **res = nullptr;
    size = 0;

    while (startFrom)
    {





        // !...
        // Здесь вырезана часть кода. Ее необходимо реализовать
        // !...





    }

    // recreates array if created
    if (res)
    {





        // !...
        // А здесь вырезана еще одна часть кода. И ее тоже необходимо реализовать
        // !...





    }

    return res;
}



// Следующий фрагмент кода перестанет быть "блеклым" и станет "ярким", как только вы определите
// макрос IWANNAGET10POINTS, взяв тем самым на себя повышенные обязательства
#ifdef IWANNAGET10POINTS

template <typename T>
typename BidiLinkedList<T>::Node**
BidiLinkedList<T>::cutAll(Node* startFrom, const T& val, int& size)
{

    // !...
    // Реализуй метод, если хочешь получит оценку повыше!
    // !...


}

#endif // IWANNAGET10POINTS