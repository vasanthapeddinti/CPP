class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        int vis[V] = {0};
        
        vis[0] = 1;
        
        queue<int> q;
        
        int i = 0; // always starting index
        q.push(i);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            ans.push_back(cur);
            
            for (auto it : adj[cur]) {
                if (vis[it] == 0){
                    vis[i] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
        
    }
};