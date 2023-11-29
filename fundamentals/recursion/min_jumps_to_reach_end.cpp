/*

Given an array nums of positive numbers, start from the first index and 
reach the last index with the minimum number of jumps, where a number at 
an index represents the maximum jump from that index.
For example, if the value at the current index is 3, then a maximum of 3 
and a minimum of a 1 step jump can be taken in the direction of the last 
index of the array. You cannot move in the opposite direction, that is, 
away from the last index.

ex:

[2, 3, 1, 5, 7]
 0  1  2  3  4

At 0th, jump 1
Go to index 1
At 1st index, jump 3
Dest reached
*/


#include <iostream>
#include <vector>
#include <limits>

long FindMinJumpsRecursive(std::vector<int>& nums, int index) {
	int n = nums.size();
	// If we have reached the last index
	if (index >= n - 1)
		return 0;

	// Initializing jumps with maximum value. It will store 
  	// the minimum jumps required to reach the current index
	long jumps = std::numeric_limits<int>::max();

	// Checking all the possible jumps
	for (int i = index + 1; i <= index + nums[index]; i++) {
		// Selecting the minimum jump
		jumps = std::min(jumps, FindMinJumpsRecursive(nums, i) + 1);
	}

	return jumps;
}

long FindMinJumps(std::vector<int>& nums) {
	return FindMinJumpsRecursive(nums, 0);
}

// Driver code
int main() {
	std::vector<std::vector<int>> inputs = {{7}, {1, 0}, {2, 3, 1, 1, 4}, {2, 1, 1, 1, 4}, {1, 1, 3, 6, 9, 3, 0, 1, 3}};

	// You can uncomment the line below and check how this recursive solution causes a time-out 
    // inputs.push_back({2, 9, 4, 6, 1, 4, 7, 10, 0, 3, 9, 7, 4, 10, 5, 9, 3, 9, 7, 7, 10, 1, 8, 5, 9, 3, 1, 5, 9, 7, 7, 6, 3, 9, 7, 0, 1, 9, 9, 0, 9, 4, 9, 6, 2, 9, 3, 7, 6, 4});
	
	for (int i = 0; i < inputs.size(); i++) { 
		std::cout << i + 1 << ". " << "[";
		for (int x = 0; x < inputs[i].size(); x++) {
			if (x == (inputs[i].size() - 1)) {
				std::cout << inputs[i][x] << "]" << std::endl;
			}
			else {
				std::cout << inputs[i][x] << ", ";
			}
		} 
		std::cout << "Minimum jumps to reach the end: " << FindMinJumps(inputs[i]) << std::endl;
    	std::cout << std::string(100, '-') << "\n\n";
	}
}