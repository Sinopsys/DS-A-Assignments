////////////////////////////////////////////////////////////////////////////////
// Module Name:  int_stack.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures"
// provided by  the School of Software Engineering of the Faculty
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include <stdexcept>

// TODO: add necessary headers here
// #include <...
#include "int_stack.h"

namespace xi
{

    using std::logic_error;

// TODO: add method definitions here



    IntStack::IntStack(size_t sz)
    {
        if (sz > 0)
        {
            _ssize = sz;
            _stack = new int[_ssize];

            //
            // I used head to store the currnet number of elemnets in the array
            // and head -1 will be the index of the last added element.
            _head = 0;
        }
    }

    void IntStack::push(int el)
    {
        if (_head >= _ssize)
        {
            throw logic_error("Stack is full.");
        }
        _stack[_head++] = el;
    }

    IntStack::~IntStack()
    {
        delete _stack;
        _head = 0;
    }

    int IntStack::pop()
    {
        if (_head <= 0)
        {
            throw logic_error("Stack is empty.");
        }
        return _stack[--_head];
    }

    int IntStack::top()
    {
        if (_head <= 0)
        {
            throw logic_error("Stack is empty.");
        }
        return _stack[_head - 1];
    }

    void IntStack::clear()
    {
//        _stack = {0};
        _head = 0;
    }

    bool IntStack::isEmpty() const
    {
        return _head == 0;
    }

    bool IntStack::isFull() const
    {
        return _head == _ssize;
    }


} // namespace xi

// EOF
