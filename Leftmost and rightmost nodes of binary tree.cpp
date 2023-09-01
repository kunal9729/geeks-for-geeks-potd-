void printCorner(Node *root)
{
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        queue<Node *> next;
        
        Node * first = q.front();
        Node * last = first;
        
        while(!q.empty()){
            Node * cur = q.front();
            last = cur;
            q.pop();
            
            if(cur -> left != nullptr)
                next.push(cur -> left);
            if(cur -> right != nullptr)
                next.push(cur -> right);
        }
        
        q = next;
        
        cout << first -> data << ' ';
        if(last != first)
            cout << last -> data << ' ';
    }
}
