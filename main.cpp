#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
SC_MODULE(toplevel){

    subnet s1, s2;
    placeChannel<1,1> IDLE;

    SC_CTOR(toplevel): s1("s1"), s2("s2"), IDLE(2){
        s1.ACT.in.bind(IDLE);
        s2.ACT.in.bind(IDLE);

        s1.PRE.out.bind(IDLE);
        s2.PRE.out.bind(IDLE);

        SC_THREAD(process);
    }

    void process(){
        while (true)
        {
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.RD.fire();
            wait(10, SC_NS);
            s1.WR.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s2.PRE.fire();
            wait(10, SC_NS);
            sc_stop();
        }
    }
};

int sc_main(int, char**)
{
    // TODO
    toplevel top("top");
    sc_start();
    return 0;
};
