class Solution
{
    public:
    Node *compute(Node *head)
    {
        int MAX = -1e9;
        
        function<Node *(Node *)> traverse = [&](Node * cur) -> Node * {
            if(cur == nullptr)
                return nullptr;
                
            Node * next = traverse(cur -> next);
            
            if(next != nullptr){
                Node * todelete = cur -> next;
                cur -> next = next;
                delete(todelete);
            }
            
            MAX = max(MAX, cur -> data);
            
            return (MAX > cur -> data) ? cur -> next : nullptr;
        };
        
        Node * first = traverse(head);
        
        return (first == nullptr) ? head : first;
    }
    
};
   
