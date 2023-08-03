class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> d(N, 1e9);
        d[0] = 0;
        
        vector<vector<pair<int,int>>> g(N);
        
        for(int i = 0; i < M; i++){
            g[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            int cd, node;
            tie(cd, node) = pq.top();
            
            pq.pop();
            
            for(auto next : g[node]){
                int w, child;
                tie(child, w) = next;
                
                if(d[child] > d[node] + w){
                    d[child] = d[node] + w;
                    pq.push({d[child], child});
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            if(d[i] == 1e9)
                d[i] = -1;
        }
        
        return d;
    }
};
