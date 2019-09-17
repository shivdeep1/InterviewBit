QUES::

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

SOL::


ListNode* Solution::mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *fhead = head1;
    ListNode *ftail = head1;
    ListNode *h1 = head1;
    ListNode *h2 = head2;
    if(h1 -> val > h2 ->val)
    {   fhead = head2;
     
        ftail = head2;   // you need to update ftail also
     
        h2 = h2->next;  // and since h2 is used now so shift h2 to next
    }
    
    else h1 = h1->next;  // this means we have used h1 as fhead and so we move h1 to its next
    
    
    while(h1 != NULL && h2 != NULL) // you had used || operator , but && operator must be used since we have to work in this loop if both h1 and h2 are non-NULL
    {
        if(h1 -> val > h2 -> val)
        {
            ftail->next = h2;  // this is the way of joining h2 to the end of the linked list we are preparing
            ftail = h2;   // updating the ftail since we have attached one more element at the end
            
            h2 = h2->next;  // we have used h2 so we move it to its next
        }
        
        else  // same procedure used as above for appending h1 at the end
        {
            ftail->next = h1;
            ftail = h1;  
            
            h1 = h1->next; 
        }
        
       // head1 = head1 -> next;  : we have already moved h1 or h2 depending upon condition so no need to move head1 and head2
        //head2 = head2 -> next;
        
    }
    
    
    if(h1 == NULL)
    {
        while(h2!=NULL)   // there can be more than 1 elements left in list2 so we use loop
        {
            ftail -> next = h2;
            ftail = h2;
            h2 = h2->next;
        }
        
    }
    
    else
    while(h1!=NULL)   // same procedure as above
    {
        ftail -> next = h1;
        ftail = h1;
        h1 = h1->next;
    }
    
    
    return fhead;
}
