#include <iostream>
#include <map> 

using namespace std;

int main() {

    /*
     * Sorted keys
     * Uniquely identify the elements
     */

    map<int, int> mp0;
    mp0[1] = 2;
    mp0[0] = 4;
    mp0[5] = 6;

    for (auto it : mp0) {
        cout << it.first <<  " " << it.second << endl;
    } 

    cout << endl;

    mp0.insert({77,8});
    mp0.emplace(60,23);

    for (auto it = mp0.begin(); it != mp0.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    cout << "Is map empty: " << mp0.empty() << endl;

    auto it = mp0.find(5);
    mp0.erase(it);

    mp0.erase(77);

    for (auto it = mp0.begin(); it != mp0.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    if (mp0.count(4)) {
        cout << "Element is present in map" << endl;
    } else {
        cout << "Element is not present in map" << endl;
    }

    mp0.clear();
    cout << "Is map empty: " << mp0.empty() << endl;

    map<int, pair<int, int>> mp1;
    map<pair<int, int>, int> mp2;

    return 0;
}