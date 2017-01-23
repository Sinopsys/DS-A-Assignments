////////////////////////////////////////////////////////////////////////////////
// Module Name:  stack_machine.h/cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         23.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include "stack_machine.h"

// TODO: add necessary headers here
// #include <...


namespace xi {

//==============================================================================
// Free functions -- helpers
//==============================================================================

// TODO: if you need some free function, add their definitions here


//==============================================================================
// class PlusOp
//==============================================================================


int PlusOp::operation(char op, int a, int b, int c)
{
    if(op != '+')
        throw std::logic_error("Operation other than Plus (+) are not supported");

    // here we just ignore unused operands
    return a + b;
}

IOperation::Arity PlusOp::getArity() const
{
    return arDue;
}

//==============================================================================
// class StackMachine
//==============================================================================

// TODO: implement methods of the StackMachine class here

} // namespace xi
