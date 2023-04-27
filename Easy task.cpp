//User function Template for C++

class Solution{
public:

char solve(vector<int> &freq, int k){
    int count = 0;
    for(int i=25; i>=0; i--){
        count += freq[i];
        if(count >= k) return i + 'a';
    }
    
    return '*';
}
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        vector<char> res;
        vector<int> freq(26, 0);
        
        for(auto& query : queries){
            int queryNo = stoi(query[0]);
            if(queryNo == 1){
                int ind = stoi(query[1]);
                char ch = query[2][0];
                freq[s[ind] - 'a']--;
                freq[ch - 'a']++;
                s[ind] = ch;
            }
            else {
                int left = stoi(query[1]);
                int right = stoi(query[2]);
                
                int k = stoi(query[3]);
                for(int i=0; i<26; i++){
                    freq[i]= 0;
                }
                
                for(int i=left; i<= right; i++){
                    freq[s[i]- 'a']++;
                }
                char ch = solve(freq, k);
                res.push_back(ch);
            }
        }
        
        return res;
        
    }
};
