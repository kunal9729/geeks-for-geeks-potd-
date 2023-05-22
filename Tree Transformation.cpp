//User function Template for C++

class Solution {
public:
    int solve(int n, vector<int> positions) {
        
    
        int i, answer = n - 1;
        vector<int> degree(n + 1, 0);
        
        for (i = 1; i < n; i++) {
            degree[positions[i]]++;
            degree[i]++;
        }
        
        for (i = 0; i < n; i++) {
            if (degree[i] == 1) {
                answer--;
            }
        }
        
        if (answer < 0) {
            return 0;
        }
        
        return answer;
    }
};








