Ques:

Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]


Sol::

vector<vector<int> > Solution::solve(int A) {
     vector<vector<int> >res(A);
    for(int i=0;i<A;i++){
        for(int j=0;j<=i;j++) {
            if(i==j || i==0) {
                res[i][j]=1;
            }
        }
         //res[i].push_back(1);
    }
    for(int i=2;i<A;i++){
        for(int j=1;j<i;j++){
         res[i][j]=res[i-1][j]+res[i-1][j-1];
         //cout<<res[i][j]<<endl;
        }
    }
    return res;
}
