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
            throw logic_error("Operations other than Mul (*) are not supported");

//         here we just ignore unused operands
        return a * b;
    }

    IOperation::Arity MulOp::getArity() const
    {
        return arDue;
    }

//==============================================================================
// class AndOp
//==============================================================================


    int AndOp::operation(char op, int a, int b, int c)
    {
        if (op != '&')
            throw std::logic_error("Operations other than And (&) are not supported");

        // here we just ignore unused operands
        return a & b;
    }

    IOperation::Arity AndOp::getArity() const
    {
        return arDue;
    }

//==============================================================================
// class SubstrOp
//==============================================================================


    int SubstrOp::operation(char op, int a, int b, int c)
    {
        if (op != '-')
            throw std::logic_error("Operations other than Substraction (-) are not supported");

        // here we just ignore unused operands
        return a - b;
    }

    IOperation::Arity SubstrOp::getArity() const
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
        if (clearStack)
        {
            _s.clear();
        }
        //
        // get vector of tokens
        vector<string> tokens = splitString(expr);
        for (int i = 0; i < tokens.size(); ++i)
        {
            //
            // if it is an operand
            if (tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "&" && tokens[i] != "+")
            {
                int t = 0;
                try
                {
                    t = std::stoi(tokens[i].c_str());
                }
                catch (std::invalid_argument &e)
                {
                    throw logic_error("No conversion could be performed");
                }
                catch (std::out_of_range &e)
                {
                    throw logic_error("Converted value falls out of the range.");
                }
                catch (...)
                {
                    throw logic_error("Invalid argument.");
                }
                _s.push(t);
            } // it is n operator
            else
            {
                IOperation *operation = getOperation(tokens[i][0]);
                IOperation::Arity arity = operation->getArity();

                int op1, op2, op3, res;
                switch (arity)
                {
                    case IOperation::arUno:
                        op1 = _s.pop();
                        res = operation->operation(tokens[i][0], op1);
                        break;
                    case IOperation::arDue:
                        op2 = _s.pop();
                        op1 = _s.pop();
                        res = operation->operation(tokens[i][0], op1, op2);
                        break;
                    case IOperation::arTre:
                        op3 = _s.pop();
                        op2 = _s.pop();
                        op1 = _s.pop();
                        res = operation->operation(tokens[i][0], op1, op2, op3);
                        break;
                    default:
                        throw logic_error("Unregistered arity.");
                }
                _s.push(res);
            }
        }
        return _s.top();
    }
} // namespace xi

// EOF
