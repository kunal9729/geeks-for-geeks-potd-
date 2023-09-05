class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> g(V);
        
        for(auto i : edges){
            g[i.first].push_back(i.second);
            g[i.second].push_back(i.first);
        }
        
        return g;
    }
};
