class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node * curHead, * nextHead;
        curHead = nextHead = nullptr;
            
        function<void(node *, node *, int)> traverse = [&](node * cur, node * prev, int p) {
            if(cur == nullptr)
                return;
            
            traverse(cur -> next, cur, (p + 1) % k);

            if((cur -> next == nullptr) or (p == k - 1))
                curHead = cur;
                
            if(p == 0){
                cur -> next = nextHead;
                nextHead = curHead;
            }
            else{
                cur -> next = prev;
            }
        };
        
        traverse(head, nullptr, 0);
        
        return curHead;
    }
};

