QUES::

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.


SOL::

int Solution::lPalin(ListNode* head) {
    int c=0;
    ListNode *temp=head;
    while(temp!=NULL){        //count no of nodes
        temp=temp->next;
        c++;
    }
    
    int mid=c/2;
    int i=1;
    ListNode *h1=head;
    temp=head;
    
    while(i<mid){
        temp=temp->next;        //temp  points to mid now
        i++;
    }
    
    ListNode *h2=temp->next;
    temp->next=NULL;
    ListNode*curr=h2;
    ListNode* prev =NULL;
    ListNode* nextt=NULL;
    while(curr!=NULL){
        nextt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextt;
    }
    h2=prev;
    while(h1!=NULL&&h2!=NULL){
        if(h1->val!=h2->val)
            return 0;
        h1=h1->next;
        h2=h2->next;
    }
    return 1;
}