#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

SC_MODULE(transition)
{
    SC_CTOR(transition){        
    }

    sc_port<placeInterface<unsigned int>> in;
	sc_port<placeInterface<unsigned int>> out;

    void fire()
    {
        if (in->testTokens() > 0) {
            std::cout << this->name() << ": Fired" << std::endl;
        }
        else {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }

        in->removeTokens(1);
        out->addTokens(1);
    }
};
// Transition:
// TODO

#endif // TRANSITION_H
