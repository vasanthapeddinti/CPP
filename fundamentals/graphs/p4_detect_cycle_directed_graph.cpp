class Solution {
  private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for (auto it : adj[node]) {
            // if node is not visited
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis) == true) 
                {
                    return true;
                    
                }
            }
            // if node is visited
            else if (vis[it] && pathVis[it]) {
                return false;
            }
        }
        
        pathVis[node] = 0; // flip it if the path is already visited
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if ( dfs(i, adj, vis, pathVis) == true) {
                    return true;
                }
            }
        }
        return false;
    }

};