//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        
        int a = 0;
        
        int b = str.length()-1;
        int res=0;
        
        while(a<b) {
            
            if(str[a] == str[b]) {
                a++, b--;
            }
            else {
                
                res++;
                a=0;
                b=str.length()-res-1;
            }
        }
        
        return res;
        
    }
};

// t.c O(n)
// s.c O(1)

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
