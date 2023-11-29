/*

You are a professional robber, and after weeks of planning, you plan to 
rob some houses along a street. Each of these houses has a lot of money 
and valuables. Let’s say that you cannot rob houses adjacent to each other 
since they have security and burglar alarms installed.

Following the above-mentioned constraint and given an integer array,
money, that represents the amount of money in each house, return the 
maximum amount of money you can steal tonight without alerting the police.

Ex:

money = [,2,3,4,5]

max = 1+3+5
    = 9
*/

/*
base cases --> i <= max_length(array)

recur max(f(i+1), f(i) + f(i+2))
*/

#include <iostream>
#include <vector>

using namespace std;

int HouseThiefRec(vector<int> money, int index, int stop_size) {

    
    if (index >= stop_size) {
        return 0;
    }
    //returns the maximum of the following two values:
    //1. Leaving the current house and starting from the next house
    //2. The maximum robbery if we rob the current house along with the houses starting from the next to
    // the next house, as we cannot rob adjacent houses
    return (max((HouseThiefRec(money, index+1, stop_size)), money[index] + (HouseThiefRec(money, index+2, stop_size))));
}


int HouseThief(vector<int>& money) {
    int stop_size = money.size();

    return HouseThiefRec(money, 0, stop_size);
}

int main(){
    
    std::vector<int> list= {1, 2,3,4,5};

    std::cout<<"max robbery sum  is " + std::to_string(HouseThief(list));
    //std::cout<<"max robbery sum  is " << HouseThief(list);

}