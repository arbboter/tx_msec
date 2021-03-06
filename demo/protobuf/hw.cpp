#include "lm.helloworld.pb.h"
#include <iostream>
#include <fstream>

using namespace std;
// g++ hr.cpp lm.helloworld.pb.cc -L/home/tony/down/pbf/protobuf-3.5.1/ -L. -lprotobuf -o hw
int main(void)
{
    lm::helloworld msg1;
    msg1.set_id(101);
    msg1.set_str("hello");

    // Write the new address book back to disk.
    fstream output("./log", ios::out | ios::trunc | ios::binary);

    if (!msg1.SerializeToOstream(&output)) 
    {
        cerr << "Failed to write msg." << endl;
        return -1;
    }
    return 0;
}