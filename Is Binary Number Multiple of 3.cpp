//User function template for C++

class Solution {
public:	
    int isDivisible(string s) {
        int remainder = 0;
        
        for (char c : s) {
            int digit = c - '0'; // Convert character to integer
            
            remainder = (remainder * 2 + digit) % 3;
        }
        
        return (remainder == 0);
    }
};
