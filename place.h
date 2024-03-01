#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
template<unsigned int N = 1, unsigned int M = 1>
class placeInterface : public sc_interface{
public:
   virtual void addTokens(unsigned int n) = 0;
   virtual void removeTokens(unsigned int n) = 0;
   virtual unsigned int testTokens() = 0;
};



// Place Channel:
template<unsigned int N = 1, unsigned int M = 1>
class placeChannel : public placeInterface<N, M>{

private:
    unsigned int tokens;

public:
    //Constructor
	placeChannel(unsigned int initialTokens) {
    tokens = initialTokens;
    }

    void addTokens(unsigned int n) {
        tokens++;
    }

    void removeTokens(unsigned int n) {
        tokens--;
    }

    unsigned int testTokens() {
        return tokens;
    }    

};

#endif // PLACE_H
