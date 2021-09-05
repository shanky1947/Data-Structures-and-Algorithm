/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/

void printdfs(int **mat,bool *visited,int n,int si){
    visited[si]=true;
    for(int i=1;i<=n;i++)
        if(!visited[i] && mat[si][i]==1)
            printdfs(mat,visited,n,i);
}

int dfs(int **mat, int n){
    bool *visited=new bool[n];
    int count=0;
    for(int i=1;i<=n;i++)
        visited[i]=false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
    		printdfs(mat,visited,n,i);
        	count++;
        }
    }
    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int **mat=new int*[n+1];
    for(int i=0;i<=n;i++){
        mat[i]=new int[n+1];
    }
    int a,b;
	for(int i=0;i<m;i++){
        a=v[i]; b=u[i];
        mat[a][b]=1;
        mat[b][a]=1;
    }
    return dfs(mat,n);
    //return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;
#include "solution.h"

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
*/