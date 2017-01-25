////////////////////////////////////////////////////////////////////////////////
// Module Name:  main.cpp
// Authors:      Kupriyanov Kirill
// Group:        BSE151
// Date:         25.01.2017
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <assert.h>


#include "int_stack.h"
#include "stack_machine.h"


void testStack()
{
    xi::IntStack s;

    s.push(42);
    //int a = s.pop();
    assert(s.top() == 42);            // EXPECT_EQ()
    assert(s.pop() == 42);            // EXPECT_EQ()

    // an exception should be thrown
    bool exc = false;
    try
    {
        s.pop();
    }
    catch (std::logic_error & /*e*/)
    {
        std::cout << "An expected exception on pop() operation is succesfully catched\n";
        exc = true;
    }
    assert(exc);

    // test for overflow
    for (int i = 0; i < xi::IntStack::STACK_SIZE; ++i)
        s.push(i);

    // next element cannot be added and, thus, en exception should be thrown
    exc = false;
    try
    {
        s.push(43);
    }
    catch (std::logic_error & /*e*/)
    {
        std::cout << "An expected exception on push() operation is succesfully catched\n";
        exc = true;
    }
    assert(exc);

    //int b = 0;
}

void testStackMachine()
{
    //
    // declaring and registering operations
    xi::StackMachine sm;
    xi::PlusOp plusop;
    xi::AndOp andop;
    xi::MulOp mulop;
    xi::SubstrOp substrop;
    sm.registerOperation('+', &plusop);
    sm.registerOperation('&', &andop);
    sm.registerOperation('-', &substrop);
    sm.registerOperation('*', &mulop);

    //
    // Check for subtraction operation
    int res = sm.calculate("5 3 -");
    int r = sm.getStack().top();
    assert(res == 2);
    assert(r == 2);

    //
    // Check for plus operation
    int res1 = sm.calculate("15 12 +");
    int r1 = sm.getStack().top();
    assert(res1 == 27);
    assert(r1 == 27);

    //
    // check for AND operation
    int res2 = sm.calculate("5 4 &");
    int r2 = sm.getStack().top();
    assert(res2 == 4);
    assert(r2 == 4);

    //
    // Check for plus operation again
    int res3 = sm.calculate("7 8 10 + +");
    int r3 = sm.getStack().top();
    assert(res3 == 25);
    assert(r3 == 25);

    //
    // check for complex set of operations
    int res4 = sm.calculate("1 5 - 6 + 2   + 4 & 2 - 7 * 8 10 + +");
    int r4 = sm.getStack().top();
    assert(res4 == 32);
    assert(r4 == 32);
}


int main()
{
    testStack();
    testStackMachine();
    return 0;
}
