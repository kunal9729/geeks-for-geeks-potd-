class Solution{
    public:
    vector<string> permutation(string S)
    {
        vector<string> ans;
        string cur = "";
        vector<bool> vis(S.size(), 0);
        
        function<void()> helper = [&]() {
            if(cur.size() == S.size()){
                ans.push_back(cur);
                return;
            }
            
            for(int i = 0; i < S.size(); i++){
                if(!vis[i]){
                    cur.push_back(S[i]);
                    vis[i] = 1;
                    helper();
                    vis[i] = 0;
                    cur.pop_back();
                }
            }
        };
        
        helper();
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
