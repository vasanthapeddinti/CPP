// from educative.io
#include <iostream>
#include <vector>
#include<algorithm>

int LcsLengthRec(std::string & s1, std::string & s2, int i, int j, int count) {
    // base case of when either string has been exhausted
    if (i >= s1.size() || j >= s2.size()) {
        return count;
    }
    // if i and j characters match, increment the count and compare the rest of the strings
    if (s1[i] == s2[j]) {
        count = LcsLengthRec(s1, s2, i + 1, j + 1, count + 1);
    }
    // compare s1[i:] with s2, s1 with s2[j:], and take max of current count and these two results
    return std::max(count, std::max(LcsLengthRec(s1, s2, i + 1, j, 0), LcsLengthRec(s1, s2, i, j + 1, 0)));
}

int LcsLength(std::string s1, std::string s2) {
    return LcsLengthRec(s1, s2, 0, 0, 0);
}

// Driver code
int main() {
    std::vector < std::string > s1 = {
        "educative",
        "bcdcdcd",
        "arefun",
        "yourocks",
        "abc"
    };
    std::vector < std::string > s2 = {
        "education",
        "aacdcdcd",
        "isfun",
        "youawesome",
        "def"
    };

    // You can uncomment the two lines below and check how this recursive solution causes a time-out 

    // s1.push_back("ypzrvyigwdiqrnbglvviozqzruvmwivgvqvrfhqi");
    // s2.push_back("wdiqrnbglvviozqzruvmwivgvqvrfhqiypzrvyigwdiqrn");

    for (int i = 0; i < s1.size(); i++) {
        std::cout << i + 1 << ".\tstring 1: \"" << s1[i] << "\" \n\tstring 2: \"" << s2[i] << "\"" << std::endl;
        int result = LcsLength(s1[i], s2[i]);
        std::cout << "\n\tThe Length of Longest Common Substring is: " << result << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }

    return 0;

}

// O(3 ^ (m+n)) - time complexity

/*
// DP solution for it


#include <iostream>
#include <vector>
#include<algorithm>

int LcsLengthRec(std::string & s1, std::string & s2, int i, int j, int count, std::vector < std::vector < std::vector < int >>> & memo) {
    // base case of when either string has been exhausted
    if (i >= s1.size() || j >= s2.size()) {
        return count;
    }
    if (memo[i][j][count] != -1) {
        return memo[i][j][count];
    }
    int c = count;
    // if i and j characters match, increment the count and compare the rest of the strings
    if (s1[i] == s2[j]) {
        c = LcsLengthRec(s1, s2, i + 1, j + 1, count + 1, memo);
    }
    // compare s1[i:] with s2, s1 with s2[j:], and take max of current count and these two results
    memo[i][j][count] = std::max(c, std::max(LcsLengthRec(s1, s2, i + 1, j, 0, memo), LcsLengthRec(s1, s2, i, j + 1, 0, memo)));
    return memo[i][j][count];
}

int LcsLength(std::string s1, std::string s2) {
    // Creating and initializing 3D table to use as memoization
    std::vector < std::vector < std::vector < int >>> memo(s1.size(), std::vector < std::vector < int >> (s2.size(), std::vector < int > (s1.size() > s2.size() ? s1.size() : s2.size(), -1)));
    return LcsLengthRec(s1, s2, 0, 0, 0, memo);
}

// Driver code
int main() {
    std::vector < std::string > s1 = {
        "educative",
        "bcdcdcd",
        "arefun",
        "yourocks",
        "abc"
    };
    std::vector < std::string > s2 = {
        "education",
        "aacdcdcd",
        "isfun",
        "youawesome",
        "def"
    };

    // Let's uncomment this to see the benefit of using dynamic programming with memoization

    //   s1.push_back("ypzrvyigwdiqrnbglvviozqzruvmwivgvqvrfhqi");
    //   s2.push_back("wdiqrnbglvviozqzruvmwivgvqvrfhqiypzrvyigwdiqrn");

    for (int i = 0; i < s1.size(); i++) {
        std::cout << i + 1 << ".\tstring 1: \"" << s1[i] << "\" \n\tstring 2: \"" << s2[i] << "\"" << std::endl;
        int result = LcsLength(s1[i], s2[i]);
        std::cout << "\n\tThe Length of Longest Common Substring is: " << result << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }

    return 0;

}

*/