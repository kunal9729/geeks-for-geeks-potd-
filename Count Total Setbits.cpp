/*********************************************************************************/

class Solution {
    long long calculateSum(long long x) {
        long long sum = (x * 1ll * pow(2, x - 1) * 1ll) + 1;
        return sum;
    }
    
public:
    long long countBits(long long n) {
        long long sum = 0;
        
        while (n) {
            long long exponent = log2(n);
            
            if (sum != 0)
                sum += n;
                
            sum += calculateSum(exponent);
            n -= pow(2, exponent);
        }
        
        return sum;
    }
};

