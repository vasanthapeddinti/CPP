#include <iostream>
#include <queue>

using namespace std;

int main() {
    /*
     * first element is always the greatest of the elements - Max Heap
     */

    priority_queue<int> pq;
    pq.push(1);
    pq.push(22);
    pq.push(300);
    pq.emplace(4);

    cout << pq.top() << endl;

    pq.pop();
    cout << pq.top() << endl;

    /* Other functions: empty, swap*/

    /*
     * first element is always the lowest of the elements - Min Heap
     */

    priority_queue<int, vector<int>, greater<int>> mh;
    mh.push(22);
    mh.push(2);
    mh.push(13);
    cout << mh.top() << endl;

    return 0;
}