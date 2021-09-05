/*
Code : Prim's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5

*/


#include <iostream>
#include<bits/stdc++.h> 
using namespace std;
class vert{
public:
    int weight;
    int parent;
};

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

    int **mat=new int*[V];
	for(int i=0;i<V;i++){
        mat[i]=new int[V];
        for(int j=0;j<V;j++)
            mat[i][j]=0;
    }
    int w,s,d;
    for(int i=0;i<E;i++){
        cin>>s>>d>>w;
        mat[s][d]=w;
        mat[d][s]=w;
    }
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
	vert *vertex=new vert[V];
    for(int i=1;i<V;i++)
        vertex[i].weight=INT_MAX;
    vertex[0].parent=-1;
    vertex[0].weight=0;
    
    int count=0;
    while(count<V){
        int mini=INT_MAX, j;
        for(int i=0;i<V;i++)
            if(!visited[i] && vertex[i].weight<mini){
                mini=vertex[i].weight;
                j=i;
            }
        visited[j]=true;
        count++;
        for(int i=0;i<V;i++)
            if(!visited[i] && mat[i][j]!=0)
                if(mat[i][j]<vertex[i].weight){
                    vertex[i].weight=mat[i][j];
                    vertex[i].parent=j;
                }
    }
    for(int i=1;i<V;i++)
        cout<<min(i,vertex[i].parent)<<" "<<max(i,vertex[i].parent)<<" "<<vertex[i].weight<<endl;
  return 0;
}

/*
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int findMin(int n, bool*visited, int weight[] ){
    int min = INT_MAX;
    int j=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(min>weight[i]){
                min = weight[i];
                j=i;
            }
        }
    }
    return j;
}



int main()
{
  int n, e, tempX, tempY;
  cin >> n >> e;
    
       
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int [n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    
    
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b] = c;
        edges[b][a] = c;
    }
    
    
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    int weight[n];
    weight[0] = 0;
    for(int i=1;i<n;i++){
        weight[i] = INT_MAX;
    }
    
    int parent[n];
    parent[0] = -1;
    
    
    for(int i=0;i<n;i++){
        int current = findMin(n,visited,weight);
        visited[current] = true;
        for(int j=0;j<n;j++){
            if(edges[current][j]!=0 && !visited[j]){
                if(edges[current][j]<weight[j]){
                    weight[j] = edges[current][j];
                    parent[j] = current;
                }
            }
        }
    }
    
    for(int i=1;i<n;i++){
        cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<edges[i][parent[i]]<<endl;

    }
    
    
    

  return 0;
}
*/