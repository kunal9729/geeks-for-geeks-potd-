//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

void insert(TrieNode* root, string key) {
    for (char c : key) {
        if (!root->children.count(c))
            root->children[c] = new TrieNode();
        root = root->children[c];
    }
}

bool search(TrieNode* root, string key) {
    for (char c : key) {
        if (!root->children.count(c))
            return false;
        root = root->children[c];
    }
    return true;
}

class Solution {
public:
    int prefixSuffixString(vector<string>& s1, vector<string>& s2) {
        TrieNode* root = new TrieNode();
        for (string s : s1) {
            insert(root, s);
            reverse(s.begin(), s.end());
            insert(root, s);
        }
        int ans = 0;
        for (string s : s2)
            if (search(root, s) || search(root, string(s.rbegin(), s.rend())))
                ans++;
        return ans;
    }
};


//T.c O(nm)
//S.c O(nm)

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
