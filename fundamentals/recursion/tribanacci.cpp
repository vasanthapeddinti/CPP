// Return the nth tribanacci number

#include <iostream>
using namespace std;

int tribanacci (int n) {

    if (n < 2) {
        return n;
    }

    if (n == 2) {
        return 1;
    }

    return (tribanacci(n-1) + tribanacci(n-2) + tribanacci(n-3));

}


int main() {

    int result=0;
    int f = 4;

    result = tribanacci(5);

    cout << "the result is " << result;
    
    return 0;
}