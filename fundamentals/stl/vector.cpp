#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print_vector(vector<int> &v) {
    for (auto x : v) {
        cout<< x << " ";
    }
    cout<<endl;
}

int main() {

    /*
     * Internally vector is implemented as a singly linked list
     */

    /*----------------*/
    vector<int> v0{ 10, 20, 30 };
    v0.push_back(12);
    print_vector(v0);


    /*----------------*/
    vector<int> v1(3, 99);
    v1.push_back(12);
    print_vector(v1);

    /*----------------*/
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v2.emplace_back(2);
    print_vector(v2);

    /*----------------*/
    vector<pair<int,int>> v3;
    v3.push_back({1,2});
    v3.emplace_back(3,4);
    for (auto it : v3) {
        cout<< it.first << " " << it.second << "\t";
    }
    cout<<endl;

    /*----------------*/
    vector<int> v4(5, 0);
    print_vector(v4);

    /*----------------*/
    vector<int> v5{1, 2, 3, 4, 5, 6};
    print_vector(v5);
    vector<int> v6(v5);
    print_vector(v6);

    /*----------------*/
    vector<int> v7{11, 22, 33, 44, 55, 66};
    for (int i = 0; i < v7.size(); i++) {
        cout << v7[i] << " "; // C-style access
    }
    cout << endl;

    for (vector<int>::iterator it = v7.begin(); it != v7.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    for (auto it = v7.begin(); it != v7.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    for (auto element : v7) {
        cout<< element << " ";
    }
    cout<<endl;

    /*----------------*/
    vector<int> v8{11, 22, 33, 44, 55, 66};
    print_vector(v8);
    v8.erase(v8.begin()+1);
    print_vector(v8);

    /*----------------*/
    vector<int> v9{11, 22, 33, 44, 55, 66};
    print_vector(v9);
    v9.erase(v9.begin() + 1, v9.begin() + 4);
    // begin of erase points to 11, begin + 1 is 22, begin + 4 points to 55, (22,33,44) are deleteed
    print_vector(v9);

    /*----------------*/
    vector<int> v10{11, 22, 33, 44, 55, 66};
    print_vector(v10);
    v10.insert(v10.begin() + 3, 333);
    print_vector(v10);

    /*----------------*/
    vector<int> v11{11, 22, 33, 44, 55, 66};
    vector<int> v12{200, 300};
    print_vector(v11);
    v11.insert(v11.begin() + 1, v12.begin(), v12.end());
    print_vector(v11);

    /*----------------*/
    vector<int> v13{11, 22, 33, 44, 55, 66};
    print_vector(v13);
    v13.insert(v13.begin(), 2, 100);
    print_vector(v13);

    /*----------------*/
    vector<int> v14{11, 22, 33, 44, 55, 66};
    print_vector(v14);
    cout << "The size of vector is " << v14.size() << endl;

    /*----------------*/
    vector<int> v15{11, 22, 33, 44, 55, 66};
    vector<int> v16{1,2,3};
    print_vector(v15);
    print_vector(v16);
    v15.swap(v16);
    print_vector(v15);
    print_vector(v16);

    /*----------------*/
    vector<int> v17{11, 22, 33, 44, 55, 66};
    print_vector(v17);
    cout << "Is the vector empty: " << v17.empty() << endl;
    v17.clear();
    print_vector(v17);
    cout << "Is the vector empty: " << v17.empty() << endl;

    /*----------------*/
    vector<int> v18{11, 22, 33, 44, 55, 66};
    print_vector(v18);
    v18.pop_back();
    print_vector(v18);

    return 0;
}