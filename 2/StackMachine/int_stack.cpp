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
            _stack = new int[sz];
        }
    }

    void IntStack::push(int el)
    {
        if (_ssize == STACK_SIZE)
        {
            throw logic_error("Stack is full.");
        }
        _stack[_ssize] = el;
    }

    IntStack::~IntStack()
    {
        delete _stack;
    }

    int IntStack::pop()
    {
        if (_ssize == 0)
        {
            throw logic_error("Stack is empty.");
        }
        int tmp = _stack[_ssize - 1];
        _stack[_ssize - 1] = 0;
        return tmp;
    }

    int IntStack::top()
    {
        if (_ssize == 0)
        {
            throw logic_error("Stack is empty.");
        }
        int tmp = _stack[_ssize - 1];
        return tmp;
    }

    void IntStack::clear()
    {
        _stack = {0};
    }

    bool IntStack::isEmpty() const
    {
        return _ssize == 0;
    }

    bool IntStack::isFull() const
    {
        return _ssize == STACK_SIZE;
    }


} // namespace xi

// EOF
