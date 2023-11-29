//: C03:ArrayAddresses.cpp
#include <iostream>
#include <unistd.h>  


using namespace std;
int main(int argc, char* argv[]) {
    //sleep(10);

    if (argc < 10) {
        cout << "number of arguments are " << argc << endl;
    }
    else {
        cout << "forget abiut it!" << endl;
    }
    
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
} ///:~