/*
Code : Edit Distance (Memoization and DP)
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/
#include<iostream>
#include<cstring>
using namespace std;


int helper(string s1, string s2,int**ans){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */

	//write your code here
    int m=s1.size();
    int n=s2.size();
    
    if(ans[m][n]!=-1)
        return ans[m][n];
    if(s1.empty() || s2.empty())
        return max(m,n);
   
    
	int result;
    if(s1[0]==s2[0]){
        result = helper(s1.substr(1),s2.substr(1),ans); 
    }else{
    int a = helper(s1.substr(1),s2,ans);
    int b = helper(s1,s2.substr(1),ans);
    int c = helper(s1.substr(1),s2.substr(1),ans);
        result = min(a,min(b,c))+1;
    }
	ans[m][n] =result;
    
    return result;
    
}




int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int m=s1.size();
    int n = s2.size();
	int**ans = new int* [m+1];
    for(int i=0;i<=m;i++)
    {
        ans[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            ans[i][j]=-1;
        }
    }
    
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            if(i==0 || j==0){
                ans[i][j] = max(i,j);
            }else{
                
            }
    }
    
    return helper(s1,s2,ans);

}

