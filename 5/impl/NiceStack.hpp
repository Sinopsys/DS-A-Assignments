//
// Created by kirill on 13.02.17.
//

/**
    Implementation of NiceStack
    NiceStack.hpp

    @author Kirill Kupriyanov
    @group  BSE151
    @date   14.02.17
*/


#include "NiceStack.h"

using std::vector;
using std::out_of_range;

template<typename T>
NiceStack<T>::NiceStack(size_t capacity)
{
    m_capacity = capacity;
    storage.reserve(m_capacity);
    iHead = 0;
}

template<typename T>
size_t NiceStack<T>::size() const
{
    return iHead;
}

template<typename T>
NiceStack<T>::~NiceStack(void)
{
    iHead = 0;
    m_capacity = 0;
    storage.clear();
}

template<typename T>
void NiceStack<T>::push(T newelement) throw(out_of_range)
{
    if (iHead == m_capacity)
        throw out_of_range("Attempting to push to a stack "
                                   "fatal error: full stack.");

    // create an element to push and assign it
    //
    TypeElementStack typeElementStack;
    typeElementStack.first = newelement;

    // find if the previous min should go as a .second or the new elem
    //
    if (iHead == 0 || newelement < storage[iHead - 1].second)
        typeElementStack.second = newelement;
    else
        typeElementStack.second = storage[iHead - 1].second;

    storage.push_back(typeElementStack);
    ++iHead;
}


template<typename T>
T NiceStack<T>::pop(void) throw(out_of_range)
{
    if (iHead != 0)
    {
        TypeElementStack temp = storage[iHead - 1];
        storage.pop_back();
        --iHead;
        return temp.first;
    }
    throw out_of_range("Attempting to pop from a stack fatal error: stack is empty.");
}

template<typename T>
T NiceStack<T>::getMinimum(void) throw(out_of_range)
{
    if (iHead != 0)
        return storage[iHead - 1].second;
    throw out_of_range("Attempting to get the min from a stack "
                               "fatal error: no elements in the stack");
}

// EOF
