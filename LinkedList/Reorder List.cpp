QUES::

Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.


SOL::

ListNode* Solution::reorderList(ListNode* A) {
 vector<int> v;
    ListNode* sA = A;
    while(A)
    {
        v.push_back(A->val);
        A = A->next;
    }
    int sz = v.size();
    A = sA;
    int i = 0;
    while(1)
    {
        A->val = v[i];
        A = A->next;
        if(i >= sz-i-1)
            break;
        A->val = v[sz-i-1];
        A = A->next;
        i++;
        if(i > sz-i-1)
            break;
    }
    return sA;
}