class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        function<bool(Node *, Node *)> dfs = [&](Node * node1, Node * node2) -> bool {
            if(!node1 ^ !node2)
                return 0;
            if(!node1 and !node2)
                return 1;
                
            if(node1 -> data != node2 -> data)
                return 0;
                
            bool ok = 0;
                
            ok = ok or (dfs(node1 -> left, node2 -> left) and dfs(node1 -> right, node2 -> right));
            
            swap(node1 -> left, node1 -> right);
            
            ok = ok or (dfs(node1 -> left, node2 -> left) and dfs(node1 -> right, node2 -> right));
            
            return ok;
        };
        
        return dfs(root1, root2);
        
    }
};
