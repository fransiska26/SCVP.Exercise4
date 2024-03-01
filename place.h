#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
template <class T>
class placeInterface : public sc_interface{
public:
   virtual void addTokens(unsigned int n) = 0;
   virtual void removeTokens(unsigned int n) = 0;
   virtual unsigned int testTokens() = 0;
};



// Place Channel:
class placeChannel : public placeInterface<unsigned int>{

private:
    unsigned int tokens;

public:
    //Constructor
	placeChannel(unsigned int initialTokens) {
    tokens = initialTokens;
    }

    void addTokens(unsigned int n) override{
        tokens++;
    }

    void removeTokens(unsigned int n) override{
        tokens--;
    }

    unsigned int testTokens() override{
        return tokens;
    }    

};

#endif // PLACE_H
