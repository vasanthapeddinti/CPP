#include <iostream>
#include <set>

using namespace std;

void print_multiset(multiset<int> m) {
    for (auto x : m) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    /*
     * multiple elements can have equivalent values
     * elements can't be modified
     * elements are sorted
     * Iterators are allowed
     */
    multiset<int> m1;
    m1.insert(1);
    m1.insert(1);
    m1.insert(1);
    m1.insert(22);
    m1.insert(10);
    m1.insert(10);
    m1.insert(13);
    m1.insert(123);
    m1.insert(13);

    print_multiset(m1);

    m1.erase(1); // erases all occurences of 1
    print_multiset(m1);

    int cnt = m1.count(13);

    m1.erase(m1.find(13)); // find returns the address not value. So, only the first occurence is deleted
    print_multiset(m1);

    //m1.erase(m1.find(1), m1.find(1)+2)
    return 0;
}