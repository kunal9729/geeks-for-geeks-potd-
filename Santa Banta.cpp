//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
void DFS(int node, vector<bool>& vis, vector<vector<int>>& g, int& size) {
    size++;
    vis[node] = true;
    for (int it : g[node]) {
        if (!vis[it])
            DFS(it, vis, g, size);
    }
}

vector<int> prime;
void precompute() {
    vector<bool> isprime(1000001, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= 1000000; i++) {
        if (isprime[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j <= 1000000; j += i)
                isprime[j] = false;
        }
    }
}

int helpSanta(int n, int m, vector<vector<int>>& g) {
    int maxsize = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int size = 0;
            DFS(i, vis, g, size);
            maxsize = max(maxsize, size);
        }
    }
    return (maxsize == 1) ? -1 : prime[maxsize - 1];
}

};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends
