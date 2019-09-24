QUES::

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 

SOL::

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* rev(ListNode *A){
      ListNode *prev=NULL;
    ListNode *curr=A;
    ListNode *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
 }
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(m==n) return A;
    ListNode *temp=A,*first=A,*last=A,*prev=NULL;
    int i=1;
    for(;i<m;i++){
     prev=temp;
     temp=temp->next;
    }
   
   first=temp;
   
    for(;i<n;i++)
     temp=temp->next;
    last=temp;
    
    ListNode* next=last->next;
    last->next=NULL;
    
    first=rev(first);
    
    if(prev!=NULL)prev->next=first;
    else A=first;
    temp=first;
    while(temp->next!=NULL)
     temp=temp->next;
    
    temp->next=next;
    return A;
}
