// 
class Solution{
    public:
        int modulo(string s, int m){
            int ans = 0;
            for (char c : s) {
                ans = (ans * 2 + (c - '0')) % m;
                
            }
            return ans;
            
        }
        
};


            
        

    
   
    
        
    
    
