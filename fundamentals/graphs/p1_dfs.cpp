// map can be replaced with list
// In cpp, list is not a contiguos DS like array and vector

// We construct a graph by adding Edges
// Using that we construct adjacency list which is actually map

/*

vertex (int)  :   list/vector
     2        :     4,5
     4        :     5
     5        :     2,33
     33       :     2, 5
*/

// Define a map visited {vertex : bool} which represents if vertex is visited or not
// Start at a node and check print it
// Start a for loop for the coresponding value which is a list and if it is not present in the visited map
// recursively call the elements inside the list.


#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Graph {
    public:
        map<int, bool> visited;
        map<int, vector<int>> adj;
        
        void addEdge(int src, int dst) {
            adj[src].push_back(dst);
        }
        
        void DFS(int vertex) {
            visited[vertex] = true;
            cout<<vertex<< " ";
            
            for (auto i=adj[vertex].begin(); i!=adj[vertex].end(); ++i) {
                if (!visited[*i]){
                    DFS(*i);
                }
            }
        }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.DFS(2);
    
    return 0;
}

/*

Sample output:

2 0 1 3 

*/


/*
// gfg solved solution

class Solution {
  public:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans) {
        vis[node] = 1;
        ans.push_back(node);
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
               dfs(it, adj, vis, ans); 
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        int start = 0;
        vector<int> ans;
        dfs(start, adj, vis, ans);
        return ans;
    }
};
   

*/







