QUES::


Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.


SOL::

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
   
     ListNode* curr = A;
    ListNode* prev;
    
    if(A == NULL){
        return A;
    }
    
    int size = 0;
    
    while(curr != NULL){
        curr = curr->next;
        size++;
    }
    
    int rem = size-B;
    
    if(rem <= 0){
        return A->next;
    }
    
    curr = A;
    
    while(rem > 0){
        prev = curr;
        curr = curr->next;
        rem--;
    }
    
    prev->next = curr->next;
    delete(curr);
    return A;
}
