// Return the nth fibanocci number

#include <iostream>
using namespace std;

int fibanocci (int n) {

    if (n < 2) {
        return n;
    }

    return (fibanocci(n-1) + fibanocci(n-2));

}


int main() {

    int result=0;
    int f = 4;

    result = fibanocci(4);

    cout << "the result is " << result;
    
    return 0;
}