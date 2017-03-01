#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

#include "simulator.h"
#include "fifo.h"

using namespace std;

int main(int argc, char *argv[])
{


    string file = "bigfirst.run";
    simulator *s = new fifo(2);
    s->simulate(file);
    delete s;

    return EXIT_SUCCESS;
}
