class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        vector<int> f(1e4 + 10, 0);
        
        Node * prev = nullptr;
        Node * cur = head;
        
        while(cur != nullptr){
            ++f[cur -> data];
            
            if(f[cur -> data] > 1)
                prev -> next = cur -> next;
            else
                prev = cur;
            
            cur = cur -> next;
        }
        
        return head;
    }
};
