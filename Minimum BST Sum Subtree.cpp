//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
       int minNodes = INT_MAX;
       
       
    // Define a struct to hold information about a subtree.
       struct Pair {
           int minVal;
           int maxVal;
           int sum;
           int nodeCount;
           bool isBST;
       };
       
       Pair traverse(Node* root, int target) {
            // If the current node is null, return information for an empty subtree.
           if(!root) {
               return{INT_MAX, INT_MIN, 0, 0, true};
           }
           
            // Recursively traversing
           Pair left = traverse(root -> left, target);
           Pair right = traverse(root -> right, target);
           
              // Computing
           
            int sum = left.sum + right.sum + root -> data;
            int nodeCount = left.nodeCount + right.nodeCount+1;
            int minVal = min(root->data, min(left.minVal,right.minVal));
            int maxVal = max(root->data, max(left.maxVal, right.maxVal));
            int isBST = root-> data > left.maxVal && root->data <right.minVal && left.isBST && right.isBST;
           
           
           // If the current subtree is a BST and has the target sum, update the minimum number of nodes
           if(isBST && sum == target) {
               minNodes = min(minNodes, nodeCount);
           }
           
           return{minVal, maxVal, sum, nodeCount, isBST};
       }
    int minSubtreeSumBST(int target, Node *root) {
        // Traverse the tree and compute information about each subtree.
        Pair res = traverse(root, target);
        return(minNodes == INT_MAX) ? -1 : minNodes;
    }
};
//t.c O(n)
//s.c O(h)


//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends
