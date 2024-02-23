#include <iostream>
#include <deque>

using namespace std;

void print_deque(deque<int> dq) {
    for (auto x : dq) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    /*
     * Deque - double-ended queue, implemented as dynamic array
     * sequence containers with dynamic sizes that can be extracted or contracted on both ends
     * Similar to vectors but with efficient insertion and deletion at the begining of sequeunce, not only at the end
     * Random access is possible
     */

    /*----------------*/
    deque<int> dq0 {1,2,3,4};
    dq0.push_back(12);
    print_deque(dq0);
    cout << "The element at position 3 is " << dq0[2] << endl;

    /*
     * pop_back, pop_front, begin, end, rbegin, rend, insert, size, swap, clear, empty, iterators
     */
}