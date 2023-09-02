class Solution
{
public:
    int getCount(Node *root, int k)
    {
        int ans = 0;
        
        queue<pair<Node *, int>> q;
        q.push({root, 1});
        
        while(!q.empty()){
            Node * cur;
            int level;
            
            tie(cur, level) = q.front();
            q.pop();
            
            if(cur -> left != nullptr)
                q.push({cur -> left, level + 1});
            if(cur -> right != nullptr)
                q.push({cur -> right, level + 1});
                
            if(!cur -> left and !cur -> right){
                if(level <= k){
                    k -= level;
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};
