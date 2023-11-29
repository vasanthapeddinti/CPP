/*
Suppose there is a game where a player can score either 1,2 or 4 points in each turn. Given a total score, 
n, find all the possible ways in which you can score these n points.

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
        return CountWays(n - 1) + CountWays(n - 2) + CountWays(n - 4);
}

// Driver code
int main(){
    int result = 0;

    result = CountWays(5);

    cout << "number of ways is " << result;
    return 0;
}