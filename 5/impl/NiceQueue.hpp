//
// Created by kirill on 13.02.17.
//

/**
    Implementation of NiceQueue
    NiceQueue.hpp

    @author Kirill Kupriyanov
    @group  BSE151
    @date   14.02.17
*/

#include "NiceQueue.h"

using std::out_of_range;

template<typename T>
NiceQueue<T>::NiceQueue(size_t capacity)
{
    m_capacity = capacity;
    inStack = NiceStack<T>(m_capacity);
    outStack = NiceStack<T>(m_capacity);
}


template<typename T>
size_t NiceQueue<T>::size(void) const
{
    return inStack.size() + outStack.size();
}

template<typename T>
void NiceQueue<T>::enq(T newelement) throw(out_of_range)
{
    if (size() == m_capacity)
        throw out_of_range("Attempting to enq to a queue "
                                   "fatal error: no elements in the queue.");

    inStack.push(newelement);
}

/**
 * Copies the values of s1 to s2
 * @tparam T
 * @param src stack to pop elements from
 * @param dest stack to push to
 */
template<typename T>
void copyStacks(NiceStack<T> &src, NiceStack<T> &dest)
{
    size_t k = src.size();
    for (size_t i = 0; i < k; ++i)
        dest.push(src.pop());
}


template<typename T>
T NiceQueue<T>::deq(void) throw(out_of_range)
{
    // first we need to have some elements in the second stack to copy
    // so we move contents from the first stack if second is zero
    //
    if (outStack.size() == 0 && inStack.size() != 0)
        copyStacks(inStack, outStack);

    // and if we have something in the second stack
    // we pop from it
    //
    if (outStack.size() != 0)
        return outStack.pop();

    // if both stacks are empty then we have nothing to pop
    // hence throw an out_of_range
    //
    throw out_of_range("Attempting to deq fatal error: empty queue.");
}

template<typename T>
T NiceQueue<T>::getMinimum(void) throw(out_of_range)
{
    // if we have 0 elements we have no min
    //
    if (size() == 0)
        throw out_of_range("Attempting to get the min from a queue "
                                   "fatal error: no elements in the queue.");

    // find existing minimum of 2 stacks
    //
    if (inStack.size() != 0 && outStack.size() == 0)
        return inStack.getMinimum();
    else if (inStack.size() == 0 && outStack.size() != 0)
        return outStack.getMinimum();
    else if (inStack.getMinimum() < outStack.getMinimum())
        return inStack.getMinimum();
    else
        return outStack.getMinimum();
}

// EOF
