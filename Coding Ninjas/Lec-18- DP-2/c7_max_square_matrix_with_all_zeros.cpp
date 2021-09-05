/*
Maximum Square Matrix With All Zeros
Send Feedback
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/
#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    int dp[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            if(i==0 || j==0){
                if(arr[i][j] = 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j]=0;
                }
            }else{
                if(arr[i][j]==1){
                   dp[i][j]=0; 
                }else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
	                
            }
        }
    }
    int count =0;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if(dp[i][j]>=count)
                count=dp[i][j]; 
    return count;
}


/*
#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int **output=new int*[row];
    for(int i=0;i<row;i++)
        output[i]=new int[col];
    
    int count=0;
    for(int i=0;i<col;i++)
        if(arr[0][i]==1)
            output[0][i]=0;
    	else
            output[0][i]=1;
    for(int i=0;i<row;i++)
        if(arr[i][0]==1)
            output[i][0]=0;
    	else
            output[i][0]=1;
    
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j]==1)
                output[i][j]=0;
            else
                output[i][j]=min(output[i-1][j],min(output[i][j-1],output[i-1][j-1]))+1;
        }
    }
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if(output[i][j]>=count)
                count=output[i][j];
    return count;
}
*/
