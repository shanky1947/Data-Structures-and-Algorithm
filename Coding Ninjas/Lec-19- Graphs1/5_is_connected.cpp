/*
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
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
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 

*/

#include <iostream>
using namespace std;

void check(int V,int **mat,bool *visited,int si){
    for(int i=0;i<V;i++){
        if(!visited[i] && mat[si][i]==1){
            visited[i]=true;
        	check(V,mat,visited,i);
        }
    }
}

int main() {
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
	bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    visited[0]=true;
    
    check(V,mat,visited,0);
    for(int i=0;i<V;i++)
        if(visited[i]==false){
            cout<<"false";
            return 0;
        }
    cout<<"true";
  return 0;
}

/*
#include <iostream>
#include<queue>
using namespace std;

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
    
    // print(edges,v,0,visited);
    
 
  
    queue<int> q;
    q.push(0);
    visited[0]=true;
     // cout<<edges[5][2];
    while(!q.empty()){
        
        for(int i=0;i<v;i++){
            if(edges[q.front()][i]==1 && !visited[i]){
                 q.push(i);
                visited[i]=true;
                 // cout<<i<<"hi"<<endl;
            }
            // 
        }
        
        if(q.size()==1){
            for(int i=0;i<v;i++){
                if(!visited[i]){
                    cout<<"false";
                    return 0;;
                }
            }
        }
        
        //cout<<q.front()<<" ";
        
        q.pop();
       
    }
    
    cout<<"true";
    
    
    
    
    
    
    
    
    

  return 0;
}*/