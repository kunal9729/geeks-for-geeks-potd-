Node* deleteNode(Node *head,int x)
{
    Node *toDelete;
    
    if(x == 1){
        toDelete = head;
        head = head->next;
    }else{
       Node* itr = head;
       --x;
       while(--x) 
        itr = itr->next;
       
       toDelete = itr->next;
       itr->next = itr->next->next;
    }
   
   free(toDelete);
   return head;
}
