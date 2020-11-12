/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :

*/

#include <iostream>
#include<vector>
using namespace std;

vector<int> getpath(int V,int **mat,bool *visited,int si,int ei){
    vector<int> v;
	if(si==ei){
        v.push_back(ei);
        //v.push_back(si);
        return v;
    }
    for(int i=0;i<V;i++){
        if(si==i)
            continue;
        if(!visited[i] && mat[si][i]==1){
            visited[i]=true;
            v=getpath(V,mat,visited,i,ei);
            if(v.size()!=0){
                v.push_back(si);
                return v;
            }
        }
    }
     return v;   
}
int main()
{
  int V, E;
  cin >> V >> E;

	int **mat=new int*[V];
    for(int i=0;i<V;i++){
        mat[i]=new int[V];
        for(int j=0;j<V;j++)
            mat[i][j]=0;
    }
    int a,b;
	for(int i=0;i<E;i++){
        cin>>a>>b;
        mat[a][b]=1;
        mat[b][a]=1;
    }
    int si,ei;
    cin>>si>>ei;

    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    visited[si]=true;
    vector<int> v=getpath(V,mat,visited,si,ei);
   // cout<<v.size()<<endl;
    for(int i=0;i!=v.size();i++)
        cout<<v[i]<<" ";
  return 0;
}
/*
#include <iostream>
#include <vector> 
using namespace std;
vector<int> getPath(int**edges,int s,int e,int n,bool*visited){
    vector<int> a;
    if(s==e){
        a.push_back(s);
        return a;
    }
    visited[s]=true;
    
    for(int i=0;i<n;i++){
        if(edges[s][i]==1 && !visited[i]){
            visited[i]=true;
            a = getPath(edges,i,e,n,visited);
            if(a.size()){
                a.push_back(s);
                return a;
                break;
            }
        }
         
    }
    
    
    return a;
    
}


int main()
{
  int n, E, tempX, tempY;
  cin >> n >> E;

    
     int** edges = new int*[n];
    
    
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    
     bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    int s,e;
    cin>>s>>e;
    
    vector<int> a = getPath(edges,s,e,n,visited);
    
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }

  return 0;
}
*/