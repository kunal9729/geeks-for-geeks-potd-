class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        int ans;
        
        function<void(Node *)> find = [&](Node * cur) {
            if(cur == nullptr)
                return;
                
            find(cur -> right);
            
            --K;
            if(K == 0)
                ans = cur -> data;
                
            find(cur -> left);
        };
        
        find(root);
        
        return ans;
    }
};
