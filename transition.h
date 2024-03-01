#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

template<unsigned int N=1, unsigned int M=1, unsigned int L=0>
SC_MODULE(transition)
{
    SC_CTOR(transition){        
    }

    // sc_port<placeInterface<unsigned int>> in;
	// sc_port<placeInterface<unsigned int>> out;
    
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;

    void fire()
    {
        for (unsigned int i=0; i < N; i++){ 
            if (in[i]->testTokens() <= 0) {
                std::cout << this->name() << ": NOT Fired" << std::endl;
                return;
            }
        }    

        for (unsigned int i=0; i < L; i++){ 
            if (inhibitors[i]->testTokens() > 0) {
                std::cout << this->name() << ": NOT Fired" << std::endl;
                return;
            }
        }    

        for (unsigned int i=0; i < N; i++){
            in[i]->removeTokens();
        }
        for (unsigned int i=0; i< M; i++){
            out[i]->addTokens();
        }

        std::cout << this->name() << ": Fired"  << std::endl;
        
    }
    
};
// Transition:
// TODO

#endif // TRANSITION_H
