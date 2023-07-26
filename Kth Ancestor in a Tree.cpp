int kthAncestor(Node *root, int k, int node)
{
    unordered_map<Node *, Node *> par;
    Node * start;
        
    function<void(Node *)> traverse = [&](Node * cur) {
        if(cur -> data == node)
            start = cur;
            
        if(cur -> left != nullptr){
            par[cur -> left] = cur;
            traverse(cur -> left);
        }  
        
        if(cur -> right != nullptr){
            par[cur -> right] = cur;
            traverse(cur -> right);
        }
    };
    
    par[root] = nullptr;
    traverse(root);
    
    Node * ans = start;
    while(k-- and ans != nullptr){
        ans = par[ans];
    }
    
    if(ans != nullptr)
        return ans -> data;
    
    return -1;
}
