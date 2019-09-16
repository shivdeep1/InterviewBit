QUES::

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


SOL::

ListNode* Solution::deleteDuplicates(ListNode* head) {
    
     ListNode* current = head;  
    ListNode* next_next;  
      ListNode* temp; 
    
   
    while (current->next != NULL)  
    {  
    
        if (current->val == current->next->val)  
        {  
                   
            next_next = current->next->next;  
            free(current->next);
            temp = current;
            
            current->next = next_next; 
            head = next_next;
            
            
            if(current->next->next == NULL)
            head = NULL;
            
            free(temp);
        }  
        else 
        {  
            current = current->next;  
        }
    
    }
    
  
    return head;
}