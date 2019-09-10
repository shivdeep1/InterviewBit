Ques::

Please Note:
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
This is one of those problems.
Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

 Food for thought :
Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4


SOL::

typedef long long ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
   ll n=A.size();
    ll sum=0;
    ll sumsq=0;
    for(ll i=0;i<n;i++)
    {
        sum+=(ll)A[i];
        sumsq+=((ll)A[i]*(ll)A[i]);
    }
    
    ll diff = (n*(n+1)/2)-sum;
    
    ll diff2 = ((n*(n+1)*(2*n+1))/6)-sumsq;
    
    ll sumi = diff2/diff;

    int repeated = (sumi-diff)/2;
    
    int missing = (diff+sumi)/2;
  
    vector<int> ans;
    
    ans.push_back(repeated);
    ans.push_back(missing);
    
    return ans;
}