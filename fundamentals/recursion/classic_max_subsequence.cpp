// cloud and found has "oud" sub-sequence

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <map>

// Helper function with updated signature: i is current index in str1, j is current index in str2
int LongestCommonSubsequenceHelper(std::string str1, std::string str2, int i, int j) {
    
    // base case
    if (i == str1.length() or j == str2.length())
        return 0;

    // if current characters match, increment 1
    else if (str1[i] == str2[j])
        return 1 + LongestCommonSubsequenceHelper(str1, str2, i + 1, j + 1);

    // else take max of either of two possibilities
    return std::max(LongestCommonSubsequenceHelper(str1, str2, i + 1, j),
                    LongestCommonSubsequenceHelper(str1, str2, i, j + 1));
}

int LongestCommonSubsequence(std::string str1, std::string str2) {
    return LongestCommonSubsequenceHelper(str1, str2, 0, 0);
}

// Driver Code
int main() {
    std::vector<std::string> firstStrings = {"qstw", "setter", "abcde", "partner", "freedom"};
    std::vector<std::string> secondStrings = {"gofvn", "bat", "apple", "park", "redeem"};

    // You can uncomment the lines below and check how this recursive solution causes a time-out
    // firstStrings.push_back("sjcneiurutvmpdkapbrcapjru");
    // secondStrings.push_back("oidhfwepkxwebyurtunvidqlscmjbg");

    for (int i = 0; i < firstStrings.size(); i++) {
        std::cout << i + 1 << ".\tstr1: " << firstStrings[i] << "\n\tstr2: " << secondStrings[i]
                  << "\n\n\tThe length of the longest common subsequence is: " << LongestCommonSubsequence(firstStrings[i], secondStrings[i]) << std::endl;

        std::cout << std::string(100, '-') << std::endl;
    }
}