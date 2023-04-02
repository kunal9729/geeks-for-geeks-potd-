//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:


bool is_Safe(int a, int b, int c, int d) {
    if( a < 0 || a >= c || b < 0 || b >= d) {
        
        return 0;
    }
    
    return 1;
}
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        
        
        int c = arr.size();
        int d = arr[0].size();
        int e[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int f[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        vector<vector<bool>> visited(c, vector<bool>(d));
        
        vector<int> g;
        
        queue<pair<int, int>> q;
        q.push({start_x, start_y});
        
        visited[start_x][start_y] = true;
        while(!q.empty()) {
            int size = q.size();
            int curr_leve_points = 0;
            for(int i=0; i < size; ++i) {
                pair<int, int> curr = q.front();
                q.pop();
                
                int h = curr.first;
                int m = curr.second;
                
                curr_leve_points += arr[h][m];
                for(int j=0; j < 8; ++j ) {
                    int n_h = h + e[j];
                    int n_m = m + f[j];
                    if(is_Safe(n_h, n_m, c, d ) && !visited[n_h][n_m]) {
                        visited[n_h][n_m] = true;
                        q.push({n_h, n_m});
                    }
                }
             }
             
             g.push_back(curr_leve_points);
             
        }
            
            int max = INT_MIN;
            int res = -1;
            
            for(int i=g.size()-1; i>=0; --i) {
                if(g[i] + i < g.size()) {
                    g[i] += g[i+ g[i]];
                }
            }
            
            for(int i =0; i< g.size(); ++i){
                if(g[i] > max) {
                    max = g[i];
                    res = i;
                }
            }
            
            return res;
        }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends
