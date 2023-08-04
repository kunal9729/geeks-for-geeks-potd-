class Solution{
public:
    void fix(stack<int> &St, queue<int> &q){
        if(St.empty()){
            return;
        }    
        
        q.push(St.top());
        St.pop();
        fix(St, q);
        St.push(q.front());
        q.pop();
    }
    
    void Reverse(stack<int> &St){
        queue<int> q;
        
        fix(St, q);
    }
};
