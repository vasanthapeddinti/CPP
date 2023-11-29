/*

A child is running up a staircase with n steps and can hop either 1 step, 2 steps,
 or 3 steps at a time. Your task is to count the number of possible ways that the 
 child can climb up the stairs.

*/
#include <iostream>
using namespace std;

long CountWays(int n){

    // Base Conditions
    if (n < 0)
      return 0;

    else if(n == 0)
      return 1;
  
    // Check each possible combination
    else
        return CountWays(n - 1) + CountWays(n - 2) + CountWays(n - 3);
}

// Driver code
int main(){
    int result = 0;

    result = CountWays(4);

    cout << "number of ways id " << result;
    return 0;
}