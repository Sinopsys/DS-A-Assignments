//
// Created by kirill on 27.02.17.
//

#ifndef IMPL_FIFO_H
#define IMPL_FIFO_H


#include "simulator.h"

class fifo : public simulator
{
public:
    fifo(int seconds_per_page);

    void simulate(string file_name);
};


#endif //IMPL_FIFO_H
