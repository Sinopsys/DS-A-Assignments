#include <fstream>
#include <iostream>

#include "NiceStack.h"
#include "NiceQueue.h"

using namespace std;

void testStack(int sample, int result)
{
    static int cntTest = 0;
    cntTest++;
    cout << "Stack: Test #" << cntTest;
    if (sample == result)
        cout << " -- passed";
    else	cout << " -- failed";
    cout << endl;
}

int main (int argc, char* argv[])
{
    try{
        NiceStack<int> nicestack(20);

        // Test #1
        try{
            nicestack.pop();
            testStack(-1, 1);
        }
        catch (out_of_range &ex)
        {
            testStack(1, 1);
        }
        catch (...)
        {
            testStack(-1, 1);
        }

        // Test #2
        try{
            nicestack.getMinimum();
            testStack(-1, 1);
        }
        catch (out_of_range &ex)
        {
            testStack(1, 1);
        }
        catch (...)
        {
            testStack(-1, 1);
        }

        nicestack.push(7);
        // Test #3
        testStack(7, nicestack.getMinimum());

        nicestack.push(15);
        nicestack.push(13);

        // Test #4
        testStack(7, nicestack.getMinimum());

        nicestack.push(5);

        // Test #5
        testStack(5, nicestack.getMinimum());

        nicestack.push(6);
        // Test #6
        testStack(5, nicestack.getMinimum());

        nicestack.push(3);
        // Test #7
        testStack(3, nicestack.getMinimum());

        nicestack.push(2);
        // Test #8
        testStack(2, nicestack.getMinimum());

        nicestack.push(15);
        // Test #9
        testStack(2, nicestack.getMinimum());

        nicestack.pop();
        // Test #10
        testStack(2, nicestack.getMinimum());

        nicestack.pop();
        // Test #11
        testStack(3, nicestack.getMinimum());
    }
    catch(exception &e){
        cout << e.what();
    }
    catch (...){
        cout << "Something wrong happend." << endl;
    }
    cout << endl;

    return EXIT_SUCCESS;
}
