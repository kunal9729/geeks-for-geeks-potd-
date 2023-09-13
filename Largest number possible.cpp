class Solution{
public:
    string findLargest(int N, int S){
        string ans = "";
        
        if(S == 0){
            return (N == 1) ? "0" : "-1"; 
        }
        
        while(N--){
            int cur = min(9, S);
            S -= cur;
            
            ans += (char)('0' + cur);
        }
        
        return (S > 0) ? "-1" : ans;
    }
};
