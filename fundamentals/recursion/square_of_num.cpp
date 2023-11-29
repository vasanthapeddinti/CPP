/*

In order to implement the square operation as a recursive function, 
you need first to express the operation in terms of itself:

(n-1)^2 = n^2 - 2n + 1

=> n^2 = (n-1)^2 + 2n - 1
*/

#include <iostream>

using namespace std;


int square(int x) {
    if (x == 0) {
        return x;
        }
        
    else {
        return (square(x-1) + 2*x - 1);
        }
    }


int main() {
    
    
      int input=30;
      cout << input<<"^2 = "<<square(input);

    return 0;
    }