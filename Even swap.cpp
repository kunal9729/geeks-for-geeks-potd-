//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            
            
     int index = 0;
            for(int i=0 ; i< n ; i++){
                if(a[i]%2==a[i+1]%2){
                    continue;
                }
                sort(a.begin()+index, a.begin()+ (i+1), greater<int>());
                index=i+1;
            }
            //because if any left
            sort(a.begin()+index, a.begin()+ n , greater<int>());
            return a;
        }
};
