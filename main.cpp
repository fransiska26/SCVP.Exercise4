#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
SC_MODULE(toplevel){

    transition t1, t2;
    placeChannel p1, p2;
    

    SC_CTOR(toplevel): t1("t1"), t2("t2"), p1(1), p2(0) {
        t1.in.bind(p1);
        t1.out.bind(p2);
        t2.in.bind(p2);
        t2.out.bind(p1);
        SC_THREAD(process);
    }

    void process(){
        while (true)
        {
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t2.fire();
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
