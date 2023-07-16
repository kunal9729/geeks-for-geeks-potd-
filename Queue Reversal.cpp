class Solution
{
    public:
    void helper(queue<int> &q){
        if(q.size() == 0)
            return;
            
        int x = q.front();
        q.pop();
        helper(q);
        q.push(x);
    }
    
    queue<int> rev(queue<int> q)
    {   
        helper(q);
        
        return q;
    }
};
