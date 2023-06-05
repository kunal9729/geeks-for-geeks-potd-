/*
Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int minDiff(Node* root, int K) {
        if (root == nullptr)
            return INT_MAX;
        
        if (K < root->data)
            return min(abs(root->data - K), minDiff(root->left, K));
        else if (K > root->data)
            return min(abs(root->data - K), minDiff(root->right, K));
        
        return 0;
    }
};
