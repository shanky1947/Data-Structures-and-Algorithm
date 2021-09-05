/*
Code : BFS Traversal
Send Feedback
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2

*/
#include <iostream>
#include<queue>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    queue<int> pq;
	int *visited=new int[V];
    for(int i=0;i<V;i++)
        visited[i]=0;
    
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
	
    pq.push(0);
    visited[0]=1;
    while(pq.size()!=0){
        int temp=pq.front();
        cout<<temp<<" ";
        pq.pop();
        for(int i=0;i<V;i++){
            if(temp==i)
                continue;
            if(visited[i]==1)
                continue;
            if(mat[temp][i]==1){
                visited[i]=1;
                pq.push(i);
            }
        }
        if(pq.size()==0){
            for(int i=0;i<V;i++){
                if(visited[i]==0){
                    visited[i]=1;
                    pq.push(i);
                    break;
                }
            }
        }
    }
    
	return 0;
}

/*
#include <iostream>
#include<queue>
using namespace std;


void print(int**edges,int n,int sv,bool*visited){
    
    queue<int> q;
    q.push(sv);
    visited[sv]=true;

    while(!q.empty()){
        
        for(int i=0;i<n;i++){
            if(edges[q.front()][i]==1 && !visited[i]){
                 q.push(i);
                visited[i]=true;
            }
        
        }
        
        if(q.size()==1){
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    break;
                }
            }
        }
        
        cout<<q.front()<<" ";
        
        q.pop();
       
    }
 
}

int main() {
    int v, e;
    cin >> v >> e;

    int** edges = new int*[v];
    for(int i=0;i<v;i++){
        edges[i] = new int [v];
        for(int j=0;j<v;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    
    
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    print(edges,v,0,visited);

  return 0;
}
*/