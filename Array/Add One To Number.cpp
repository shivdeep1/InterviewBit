Ques:

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

Sol:

#include<math.h>
vector<int> Solution::plusOne(vector<int> &A) {
  
    int carry=0;
    for(int i=A.size()-1;i>=0;i--){
        if(i==A.size()-1){
            A[i]+=1;
            if(A[i] == 10){
                A[i]=0;
                carry=1;
                continue;
            }
            else{
                carry=0;
                break;
            }
        }
        else if(carry==1){
            A[i]+=1;
            if(A[i] == 10){
                A[i]=0;
                carry=1;
                continue;
            }
            else{
                carry = 0;
                break;
            }
        }
    }
    if(carry==1)
        A.insert(A.begin(),1);
    while(A[0]==0)
        A.erase(A.begin());
    return A;
    
}