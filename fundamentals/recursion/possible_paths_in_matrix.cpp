/*

Given a robot located at the top-left corner of an m×n
matrix, determine the number of unique paths the robot 
can take from start to finish while avoiding all obstacles 
on the matrix. The robot can only move either down or right 
at any time. The robot tries to reach the bottom-right 
corner of the matrix. An obstacle is marked as 1, and an 
unoccupied space is marked as 0 in the matrix.

*/

/*
A naive approach is to find all the possible unique paths by traversing 
the array from start to finish. Every time, we need to check if we have 
reached the bottom-right corner of the matrix or if the iterating index 
exceeds the size of the matrix. If this condition is satisfied, we just 
stop the iteration here. If an obstacle is present in the array, the 
number of unique paths will be 0 up to that obstacle. After that, we 
will traverse to the next cell in the row and the column finding all the 
possible unique paths.
*/

#include <iostream>
#include <vector>

using namespace std;

int FindUniquePathRecursively(int i, int j, int row, int col, vector<vector<int>> matrix){

    // check if we have reached the bottom-right corner of the matrix
    if (i == row || j == col) {
        return 0;
    }

    // If an obstacle is present in the array, the number of unique paths will be 0 up to that obstacle.
    if (matrix[i][j] == 1) {
        return 0;
    }

    // check the base case when the last cell is reached
    if (i == row - 1 && j == col - 1) {
        return 1;
    }

    //traverse to the next cell in the row and the column finding all the possible unique paths.
    return ((FindUniquePathRecursively(i, j+1, row, col, matrix)) + (FindUniquePathRecursively(i+1, j, row, col, matrix)));
}

int FindUniquePath(vector<vector<int>> inputs) {
    int row = inputs.size();
    int col = inputs[0].size();

    return FindUniquePathRecursively(0, 0, row, col, inputs);
}


int main()
{
	vector<vector<int>> inputs = {
		{{0, 0, 0}, {0, 0, 0}, {0,0,0}}
	};

    int paths = FindUniquePath(inputs);
    
    cout << "No of paths is " << paths << endl;

	return 0;
}