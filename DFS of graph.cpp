class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V, 0);
        
        function<void(int)> dfs = [&](int node) {
            vis[node] = 1;
            ans.push_back(node);
            
            for(auto child : adj[node]){
                if(!vis[child])
                    dfs(child);
            }
        };
        
        dfs(0);
        
        return ans;
    }
};
