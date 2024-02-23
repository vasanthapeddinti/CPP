#include <iostream>
#include <map> 

using namespace std;

int main() {

    /*
     * Multiple keys can have same value
     * Sorted keys
     * Uniquely identify the elements
     */

    multimap<int, int> mp0;
    /* This is not possible with multimap
    mp0[1] = 2;
    mp0[0] = 4;
    mp0[5] = 6;
    */

    mp0.insert({5,8});
    mp0.insert({77,8});
    mp0.insert({77,8});
    mp0.emplace(60,23);

    for (auto it = mp0.begin(); it != mp0.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    cout << "Is map empty: " << mp0.empty() << endl;

    auto it = mp0.find(5);
    mp0.erase(it);

    mp0.erase(7);

    for (auto it = mp0.begin(); it != mp0.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    if (mp0.count(77)) {
        cout << "Element is present in map" << endl;
    } else {
        cout << "Element is not present in map" << endl;
    }

    mp0.clear();
    cout << "Is map empty: " << mp0.empty() << endl;

    multimap<int, pair<int, int>> mp1;

    return 0;
}