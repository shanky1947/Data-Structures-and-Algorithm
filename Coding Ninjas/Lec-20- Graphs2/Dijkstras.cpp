/*
Code : Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

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
    int s,d,w;
    for(int i=0;i<E;i++){
        cin>>s>>d>>w;
        mat[s][d]=w;
        mat[d][s]=w;
    }
	int *distance=new int[V];
    for(int i=0;i<V;i++)
        distance[i]=INT_MAX;
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    distance[0]=0;
    int count=0;
    while(count<=V){
        int min=INT_MAX, j;
        for(int i=0;i<V;i++)
            if(!visited[i] && distance[i]<=min){
                min=distance[i];
                j=i;
            }
        visited[j]=true;
        count++;
        for(int i=0;i<V;i++){
            if(!visited[i] && mat[i][j]!=0){
                int curr_d=distance[j]+mat[i][j];
                if(curr_d<distance[i])
                    distance[i]=curr_d;
            }
        }
    }
    for(int i=0;i<V;i++)
        cout<<i<<" "<<distance[i]<<endl;
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
    
    for(int i=0;i<n;i++){
        int current = findMin(n,visited,weight);
        visited[current] = true;
        for(int j=0;j<n;j++){
            if(edges[current][j]!=0 && !visited[j]){
                if(edges[current][j]+weight[current]<weight[j]){
                    weight[j] = edges[current][j]+weight[current];

                }
            }
        }
        
    }
    
    for(int i=0;i<n;i++){
        cout<<i<<" "<<weight[i]<<endl;
    }

  return 0;
}
*/