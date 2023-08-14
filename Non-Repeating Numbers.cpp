class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int value = 0;
        for(auto i : nums)
            value ^= i;
        
        int rightmost = (value & (value - 1)) ^ value;
        
        vector<int> ans(2, 0);
        
        for(auto i : nums){
            if(i & rightmost)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }
        
        if(ans[0] > ans[1])
            swap(ans[0], ans[1]);
            
        return ans;
    }
};
