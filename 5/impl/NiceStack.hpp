//
// Created by kirill on 13.02.17.
//

#include "NiceStack.h"

using std::vector;
using std::out_of_range;

template<typename T>
NiceStack<T>::NiceStack(size_t capacity)
{
    m_capacity = capacity;
    storage = vector<TypeElementStack>(m_capacity);
    iHead = 0;
}

template<typename T>
size_t NiceStack<T>::size() const
{
    return m_capacity;
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
    if (iHead + 1 == m_capacity)
        throw out_of_range("Stack is full.");

    TypeElementStack typeElementStack;
    typeElementStack.first = newelement;
    if (newelement < storage[iHead].second)
        typeElementStack.second = newelement;
    else
        typeElementStack.second = storage[iHead].second;

    storage.push_back(typeElementStack);
    ++m_capacity;
    if (m_capacity != 1)
        ++iHead;
}


template<typename T>
T NiceStack<T>::pop(void) throw(out_of_range)
{
    if (m_capacity == 0)
        throw out_of_range("Stack is empty.");

    TypeElementStack temp = storage[iHead];
    storage.pop_back();
    --m_capacity;
    if (m_capacity != 0)
        --iHead;
    return temp.first;
}

template<typename T>
T NiceStack<T>::getMinimum(void) throw(out_of_range)
{
    return storage[iHead].second;
}
