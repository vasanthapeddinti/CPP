#include <iostream>
#include <stack>

using namespace std;

int main() {

    /* LIFO */
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.emplace(4);

    cout << st.top() << " " << endl;
    
    st.pop();
    cout << st.top() << " " << endl;

    cout << "Size of stack is " << st.size() << endl;

    cout << "Is stack empty: " << st.empty() << endl;

    stack<int> st1;
    st1.push(11);
    st1.push(22);
    st1.push(33);
    st1.swap(st);

    cout << st.top() << " " << endl;
    cout << st1.top() << " " << endl;
    return 0;
}