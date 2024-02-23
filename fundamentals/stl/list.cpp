#include <iostream>
#include <list>

using namespace std;

void print_list(list<int> l) {
    for (auto x : l) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    /*
     * Internally list is implemented as a doubly linked list.
     * Disadvatage -  they lack direct access to the elements by their position unlike vector or array
     */

    /*----------------*/
    list<int> l0 {1,2,3,4};
    print_list(l0);

    /*----------------*/
    list<int> l1;
    l1.push_back(1);
    l1.push_back(11);
    l1.push_back(111);
    l1.push_back(1111);
    print_list(l1);
    l1.push_front(2);
    l1.push_front(22);
    print_list(l1);

    /*----------------*/
    list<int> l2;
    l2.emplace_back(1);
    l2.emplace_back(11);
    print_list(l2);
    l2.emplace_front(2);
    l2.emplace_front(22);
    print_list(l2);
    l2.pop_back();
    l2.pop_front();
    print_list(l2);

    /*
     * Other functions include :
     * pop_back, pop_front, begin, end, rbegin, rend, insert, size, swap, clear, empty, iterators
     */

    return 0;

}