#include <iostream>
#include <queue>

using namespace std;

int main() {

    /* FIFO */
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.emplace(5);

    cout << q1.front() << " " << endl;
    cout << q1.back() << " " << endl;

    q1.pop();
    cout << q1.front() << " " << endl;
    cout << q1.back() << " " << endl;

    cout << "Size of queue is " << q1.size() << endl;

    cout << "Is queue empty: " << q1.empty() << endl;

    queue<int> q2;
    q2.push(22);
    q2.push(33);

    q1.swap(q2);
    cout << q1.front() << " " << endl;
    cout << q1.back() << " " << endl;

    cout << q2.front() << " " << endl;
    cout << q2.back() << " " << endl;

    return 0;
}