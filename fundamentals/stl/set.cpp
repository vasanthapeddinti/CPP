#include <iostream>
#include <set>

using namespace std;

void print_set(set<int> s) {
    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    /*
     * stores unique values, in sorted order (ascending order), cannot be modified, but can be inserted or deleted
     * implemented as BST
     */
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(33);
    s1.emplace(4);

    print_set(s1);

    for (auto it = s1.begin(); it != s1.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    auto it1 = s1.find(3);
    auto it2 = s1.find(33);

    if (it1 == s1.end()) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found" << endl;
    }
    cout << *(it2) << endl;

    auto it3 = s1.count(1);
    auto it4 = s1.count(4);
    cout << "count of 4 is " << it3 << endl;
    /* count always returns 0 or 1. It cant have more than 1 as it holds unique values */

    s1.erase(it2);
    print_set(s1);

    auto it5 = s1.lower_bound(2);
    auto it6 = s1.upper_bound(33);
    return 0;
}