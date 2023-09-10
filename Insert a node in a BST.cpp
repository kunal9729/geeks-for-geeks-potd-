class Solution
{
    public:
    Node* insert(Node* node, int data) {
        function<Node *(Node *)> insert = [&](Node * cur) -> Node * {
            if(cur == nullptr){
                Node * newnode = new Node(data);
                return newnode;
            }
            
            if(cur -> data == data)
                return cur;
                
            if(cur -> data > data)
                cur -> left = insert(cur -> left);
            else
                cur -> right = insert(cur -> right);
                
            return cur;
        };
        
        return insert(node);
    }

};
