class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    bool change = 1;
        for(int i = 0; i < n / 2; i++){
            if(num[i] < num[n - i - 1])
                change = 1;
            else if(num[i] > num[n - i - 1])
                change = 0;
                
            num[n - i - 1] = num[i];
        }
        
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = num[i];
            
        int ind = n / 2;
        
        bool carry = change;
        while(carry and ind < n){
            if(ans[ind] == 9){
               ans[ind] = 0;
               ans[n - ind - 1] = 0;
            }
            else{
               ++ans[ind];
               ans[n - ind - 1] = ans[ind];
               carry = 0;
            }
            
            ++ind;
        }
        
        if(carry){
           ans[0] = 1;
           ans.push_back(1);
        }
            
        return ans;
	}

};
