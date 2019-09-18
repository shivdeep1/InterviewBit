Ques::

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True

SOL::


int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    int l=0,r=0;
     if(A == NULL && B == NULL){
        return 1;
    }
    else if((A == NULL && B != NULL) || (A != NULL && B == NULL)){
        return 0;
    }
    else if(A->val == B->val){
        l=isSameTree(A->left, B->left); 
        r = isSameTree(A->right, B->right);
        return l&&r;
    }
    return 0;
}