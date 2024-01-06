#include <iostream>

using namespace std;

/*
    without virtual function
*/
class base {

    public:
        void print() {
            cout << "I am in base without vf" << endl;
        }
};

class derived : public base {

    public:
        void print() {
            cout << "I am in derived class without vf" << endl;
        }
};

/*
    with virtual function
*/

class basevf {

    public:
        virtual void print() {
            cout << "I am in basevf class" << endl;
        }
};

class derivedvf : public basevf {

    public:
        void print(){
            cout << "I am in derivedvf class" << endl;
        }
};


int main() {

    derived d1;
    base *b1 = &d1;

    // The output will be "I am in base without vf" because
    // print() can not be overwritten by derived class as 
    // print() is not defined as virtual function in base class
    b1->print();

    derivedvf d2;
    basevf *b2 = &d2;

    // The output will be "I am in derivedvf class" as print()
    // function is defined as virtual function in base class
    b2->print();

    return 0;
}