class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            vector<Node *> patha, pathb;
            bool founda, foundb;
            founda = foundb = 0;
                
            function<void(Node *)> traverse = [&](Node * node) {
                if(node == nullptr)
                    return;
                    
                if(!founda)
                    patha.push_back(node);
                if(!foundb)
                    pathb.push_back(node);
                    
                if(n1 == node -> data)
                    founda = 1;
                if(n2 == node -> data)
                    foundb = 1;
                    
                traverse(node -> left);
                traverse(node -> right);
                
                if(!founda)
                    patha.pop_back();
                if(!foundb)
                    pathb.pop_back();
            };
            
            traverse(root);
            
            Node * ans = root;
            
            int ind = 0;
            
            while(ind < patha.size() and ind < pathb.size()){
                if(patha[ind] == pathb[ind])
                    ans = patha[ind++];
                else
                    break;
            }
            
            return ans;
        }

};
