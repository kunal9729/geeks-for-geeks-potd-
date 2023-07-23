class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        vector<Node*> list;
        
        while(head != nullptr){
            list.push_back(head);
            head = head -> next;
        }
        
        int i = 0;
        int j = list.size() - 1;
        int x = 0;
        
        while(x <= j){
            if(list[x] -> data == 0){
                int temp = list[x] -> data;
                list[x] -> data = list[i] -> data;
                list[i] -> data = temp;
                ++i;
                ++x;
            }
            else if(list[x] -> data == 2){
                int temp = list[x] -> data;
                list[x] -> data = list[j] -> data;
                list[j] -> data = temp;
                --j;                
            }
            else{
                ++x;
            }
        }
        
        return list[0];
    }
};
