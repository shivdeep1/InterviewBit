Ques::

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.


SOl::

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2)
        return 0;
    vector<int> b=A;
    sort(b.begin(),b.end());
    int max_diff  = INT_MIN;
    for(int i=0;i<b.size()-1;i++)
    {
        if(b[i+1]-b[i] > max_diff)
        max_diff =  b[i+1]-b[i];
    }
    return max_diff;
}
