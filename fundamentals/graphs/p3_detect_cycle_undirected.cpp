class {
  public:
    bool bfs(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        // the queue has the starting node index if. indexed as 1 or 0 and it's parent node
        q.push({src, -1});
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto adjNode : adj[node]) {
                if (!vis[adjNode]){
                    q.push({adjNode, node});
                    vis[adjNode] = 1;
                }
                // if node is already visited
                // we have to distinguish cycle from other visits
                // No guy who is previously visited and he is not the parent
                else if (parent == adjNode) {
                    return true;
                }
            }   
        }
    }

    bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        
        for (adjNode : adj[node]) {
            if (!vis[adjNode]) {
                vis[adjNode] = 1;
                if (dfs(adjNode, node, vis, adj) == true) {
                    return true; 
                }
            }
            else if (adjNode != parent) {
                return true;
            }
        }
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // bfs code
        // Code here
        int vis[V] = {0};
        
        // It works even for multiple components
        // pieces of graphs distributed will 1 to n vertices
        // so, we run for loop from 0 to n

        for (int i = 0; i < V; i++) {
            // if connected components, this will come back since 
            // it cannot visit all the nodes in one dfs or bfs
            if (!vis[i]) {
                if (bfs(i, adj, vis))
                    return true;
            }
        }
        return false;
        /*
        vector<int> vis = {0};
        for (int i = 0; i < V; i++) {
            if (dfs(i, -1, vis, adj)) {
                return true;
            }
            return false;
        */
    }
};



