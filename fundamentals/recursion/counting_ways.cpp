/*

Given a fixed list of numbers, [1,3,4], and a target number, n, count all 
the possible ways in which ncan be expressed as the sum of the given 
numb

F(n)=F(n−1)+F(n−3)+F(n−4)

Number of ways to reach n−1, as we can add 1 to reach n
Number of ways to reach n−3, as we can add 3 to reach n
Number of ways to reach n−4, as we can add 4 to reach n

*/

/*

A child is running up a staircase with n steps and can hop either 1 step, 2 steps,
 or 3 steps at a time. Your task is to count the number of possible ways that the 
 child can climb up the stairs.

*/
#include <iostream>
using namespace std;

long CountWays(int n){

	// We can not get a negative target number at any point, 
    // so we return 0 for negative values
    if (n < 0)
      return 0;

	// There is only 1 way to reach a target number of 0, 
    // by not using any available numbers
    else if(n == 0)
      return 1;
  
    // Check each possible combination
    else
        return CountWays(n - 1) + CountWays(n - 3) + CountWays(n - 4);
}

// Driver code
int main(){
    int result = 0;

    result = CountWays(5);

    cout << "number of ways is " << result;
    return 0;
}