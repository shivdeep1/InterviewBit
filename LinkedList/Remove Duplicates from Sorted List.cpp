QUES::

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

SOL::

ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* current = head;  
  
    
    ListNode* next_next;  
      
    
    if (current == NULL)  
    return head;  
  
    
    while (current->next != NULL)  
    {  
    
    if (current->val == current->next->val)  
    {  
               
        next_next = current->next->next;  
        free(current->next);  
        current->next = next_next;  
    }  
    else 
    {  
        current = current->next;  
    }  
    }
    return head;
}
