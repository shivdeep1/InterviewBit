QUES::

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

SOL::

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
   
   int count = 0, i;
   ListNode* t = A;
   ListNode* temp = A;
   ListNode* fhead=NULL;
   ListNode* ftail = NULL;
   ListNode* last = NULL;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    if(B>count)
    B=B%count;
    
    i = -(count-B);
    temp = A;
    if(temp==NULL)
        return temp;
    if(B>=count)
        return temp;
    if(B==0)
    return temp;
    while(temp!=NULL)
    {
        if(i == 0)
        {
            
            fhead = temp;
        }
        if(i== -1)
        {
            last = temp;
        }
        ftail= temp;
        temp = temp -> next;
        
        i++;
        
    }
    ftail->next = A;
    last ->next = NULL;
    
    return fhead;
}
