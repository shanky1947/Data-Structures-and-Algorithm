/*
Shortest Subsequence
Send Feedback
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3
*/

int solve(string S,string V)
{
	// Write your code here.
    int m = S.length();
    int n = V.length();

    
    
    int out[m+1][n+1] , next[m+1][n+1];
	
	for(int i = 0; i < m; i++){
		int prev = -1;
		for(int j = 0;j < n; j++){
			if(S[i] == V[j])
				prev = j;
			next[i+1][j+1] = prev;
		}
    }
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j==0)
                out[i][j] = 1;
            else if(i==0)
                out[i][j] = 1000000000;
            else{
                
//                 int index = -1;
//                 for(int q=j-1;q>=0;q--){
//                     if(V[q]==S[i-1]){
//                         index = q;
//                         break;
//                     }
//                 }
//                 if(index==-1){
//                     out[i][j] = 1;
//                     continue;
//                 }else{
//                     out[i][j] = min(out[i-1][j],out[i-1][index]+1);
//                 }
                
                if(next[i][j] == -1)
				out[i][j] = 1;
			else{
				out[i][j] = min(out[i-1][j],1 + out[i-1][next[i][j]]);
            }
                
               /*for(k=j-1;k>=0;k--)
                if(V[k]==S[i-1])
                    break;
            if(k==-1)
                output[i][j]=1;
            else
                output[i][j]=min(output[i-1][j],output[i-1][k]+1);*/
            }
        }
    }
    
    
    
    
    return out[m][n];    
}

/*
#include<bits/stdc++.h>
int solve(string S,string V)
{
    int m=S.size();
    int n=V.size();
    
	int**output=new int*[m+1];
    for(int i=0;i<=m;i++)
        output[i]=new int[n+1];
    
    for(int i=1;i<=m;i++)
        output[i][0]=1;
    for(int i=0;i<=n;i++)
        output[0][i]=100000000;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
        	int k;
            for(k=j-1;k>=0;k--)
                if(V[k]==S[i-1])
                    break;
            if(k==-1)
                output[i][j]=1;
            else
                output[i][j]=min(output[i-1][j],output[i-1][k]+1);
        }
    }
    return output[m][n];
}
*/
