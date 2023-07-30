class Solution{
  public:
    Node* succ;
    void inorder(Node* root, Node *x, Node* &prev){
        if(!root)
            return;
        
        inorder(root->left, x,prev);
        if(prev == x)
            succ = root;
        prev = root;
        inorder(root->right,x,prev);
    }
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node * prev = NULL;
        succ = NULL;
        inorder(root,x,prev);
        return succ;
    }
};
