#include <iostream>

using namespace std;


// We use a Queue and hashmap to process data of tree and get top view
// Imagine a tree with vertical lines


// Queue has a pair with data and the y co-ordinate
// The same y co-ordinate can have mutiple values
// It is the hash map that helps us to retain only the 
// top values giving us the top view vector

// hashmap has { y_co-ordinate : node->val }

vector<int> topView(Node* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    map<int, int> mp; // should be ordered map only. map stores sorted keys
    queue<pair<Node*, int>> q;

    q.push(root, 0);


    while(!q.empty) {
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int line = it.second;

        // if key not found... map.find returns end if not found
        /*
        if (mp.find(line) == mp.end()) {
            mp[line] = node->data;
        }
        */

        // Instead of the above solution, we can update 
        // the value each time, we hae with the same co-ordinate
        // So, the line below overwrites previous 

        mp[line] = node->data;

        if (node->left) {
            q.push(node->left, line - 1);
        }

        if (node->right) {
            q.push(node->right, line + 1);
        }

    }// end of while loop, you have map constructed

    for (auto i : mp) {
        ans.push_back(it.second);
    }

    return ans;
}