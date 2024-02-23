#include <iostream>
#include <unordered_set> // unordered_multiset also exists with similar properties, shares header <unordered_set> 

using namespace std;

void print_set(unordered_set<int> s) {
    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    /*
     * store unique elements in no particular order
     * immutable data
     * lower bound and upper bound functions does not work
     * all other functions are same as set
     */
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(33);
    us.emplace(4);

    print_set(us);

    for (auto it = us.begin(); it != us.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    return 0;
}