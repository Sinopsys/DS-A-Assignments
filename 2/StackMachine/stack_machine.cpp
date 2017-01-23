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

#include <stdexcept>
#include "stack_machine.h"

// TODO: add necessary headers here
// #include <...
#include <string>
#include <vector>

using std::vector;
using std::string;

namespace xi
{
    using std::logic_error;

//==============================================================================
// Free functions -- helpers
//==============================================================================

// TODO: if you need some free function, add their definitions here


//==============================================================================
// class PlusOp
//==============================================================================


    int PlusOp::operation(char op, int a, int b, int c)
    {
        if (op != '+')
            throw logic_error("Operations other than Plus (+) are not supported");

        // here we just ignore unused operands
        return a + b;
    }

    IOperation::Arity PlusOp::getArity() const
    {
        return arDue;
    }

//==============================================================================
// class MulOp
//==============================================================================


    int MulOp::operation(char op, int a, int b, int c)
    {
        if (op != '*')
            throw logic_error("Operations other than Plus (+) are not supported");

//         here we just ignore unused operands
        return a * b;
    }

    IOperation::Arity MulOp::getArity() const
    {
        return arDue;
    }


//==============================================================================
// class StackMachine
//==============================================================================

// TODO: implement methods of the StackMachine class here

    void StackMachine::registerOperation(char symb, IOperation *oper)
    {
        if (_opers.find(symb) == _opers.end())
        {
            throw logic_error("Operator exists.");
        } else
        {
            _opers[symb] = oper;
        }
    }

    IOperation *StackMachine::getOperation(char symb)
    {
        if (_opers.find(symb) == _opers.end() || _opers[symb] == nullptr)
        {
            throw logic_error("Operator is not mapped with an Operation.");
        } else
        {
            return _opers[symb];
        }
    }

    //
    // A function to split string by spaces
    vector<string> splitString(string s)
    {
        vector<string> vec;
        string tmp = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                tmp += s[i];
            } else if (tmp.size() != 0)
            {
                vec.push_back(tmp);
                tmp = "";
            }
        }
        vec.push_back(tmp);

        return vec;
    }

    int StackMachine::calculate(const std::string &expr, bool clearStack)
    {
        //
        // get vector of tokens
        vector<string> tokens = splitString(expr);
        for (int i = 0; i < tokens.size(); ++i)
        {
            //
            // if it is an operand
            if (tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "&" && tokens[i] != "+")
            {
                _s.push(atoi(tokens[i].c_str()));
            } // it is n operator
            else
            {
                IOperation::Arity arity = _opers[tokens[i][0]]->getArity();

                int op1, op2, op3;
                switch (arity)
                {
                    case IOperation::arUno:
                        op1 = _s.pop();
                        return _opers[tokens[i][0]]->operation(tokens[i][0], op1);
                    case IOperation::arDue:
                        op2 = _s.pop();
                        op1 = _s.pop();
                        return _opers[tokens[i][0]]->operation(tokens[i][0], op1, op2);
                    case IOperation::arTre:
                        op3 = _s.pop();
                        op2 = _s.pop();
                        op1 = _s.pop();
                        return _opers[tokens[i][0]]->operation(tokens[i][0], op1, op2, op3);
                }
            }
        }
        return 0;
    }
} // namespace xi

// EOF
