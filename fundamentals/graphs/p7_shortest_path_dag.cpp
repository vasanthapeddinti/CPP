class Solution {
  private:
    void topoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[]) {
        vis[node] = 1;
        
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, vis, st, adj);
            }
        }
        st.push(node);
    }
    

  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        int vis[N] = {0};
        stack<int> st;
        
        // O(N +E) - top
        for (int i = 0; i < N; i++) {
            if (vis[i] == 0) {
                topoSort(i, vis, st, adj);
            }
        }
        
        // shortest distance from source node 
        vector<int> dist(N);
        for (int i = 0; i < N; i++) {
            dist[i] = INT_MAX;
        }
        
        //int src = 6;
        dist[0] = 0;

        //O(N+M)
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt ;
                }
            }

        }
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;
        
    }
};


// Dijkstra's algorithm notes
// Can anyone confirm my understanding that we can use a simple BFS 
// also to find the shortest find. Only advantage using Dijkstra is that 
// it will make less number of calculations to find the shortest path ???

// yes you are correct, only the complexity is reduced by using priority 
// queue instead of simple queue, rest all things are same

