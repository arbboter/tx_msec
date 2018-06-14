#include "lm.helloworld.pb.h"
#include <iostream>
#include <fstream>

using namespace std;

void ListMsg(const lm::helloworld & msg)
{
    cout << msg.id() << endl;
    cout << msg.str() << endl;
}

// g++ hr.cpp lm.helloworld.pb.cc -L/home/tony/down/pbf/protobuf-3.5.1/ -L. -lprotobuf -o hr
int main(void)
{
    lm::helloworld msg1;

    fstream input("./log", ios::in | ios::binary);
    if(!msg1.ParseFromIstream(&input))
    {
        cerr << "Failed to parse address book." << endl;
        return -1;
    }
    ListMsg(msg1);
    return 0;
}
