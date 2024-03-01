#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
//template<unsigned int Win = 1, unsigned int Wout = 1>
class placeInterface : public sc_interface{
public:
   virtual void addTokens() = 0;
   virtual void removeTokens() = 0;
   virtual bool testTokens() = 0;
};



// Place Channel:
// Add Weights, modify methods
template<unsigned int Win = 1, unsigned int Wout = 1>
class placeChannel : public placeInterface{

private:
    unsigned int tokens;

public:
    //Constructor
	placeChannel(unsigned int initialTokens) {
    tokens = initialTokens;
    }

    void addTokens() override{
        tokens= tokens + Win;
    }

    void removeTokens() override {
        tokens= tokens - Wout;
    }

    bool testTokens() override{
        return tokens >= Wout;
    }    

};

#endif // PLACE_H
