class Solution
{
	public:
		vector<string> find_permutation(string S) {
    sort(S.begin(), S.end());
    vector<string> ans = {S};
    
    while (next_permutation(S.begin(), S.end())) {
        ans.push_back(S);
    }
    
    return ans;
}

};
