/*
Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
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
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include <iostream>
using namespace std;

bool findg(int **mat,bool *visited,int si,int ei,int V){
    bool so=false;
    if(mat[si][ei]==1)
        return true;
    
    for(int i=0;i<V;i++){
        if(si==i)
            continue;
        if(!visited[i] && mat[si][i]!=0){
            visited[i]=true;
            so=findg(mat,visited,i,ei,V);
            if(so==true)
                break;
            }
        }
    return so;
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
    int si,ei;
    cin>>si>>ei;
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    visited[si]=true;
	bool so=findg(mat,visited,si,ei,V);
    if(so==true)
        cout<<"true";
    else
        cout<<"false";

  return 0;
}

/*
#include <iostream>
using namespace std;

bool hasPath(int**edges,int s,int e,int n,bool*visited){
    
    
    
    
    
    if(edges[s][e]==1){
        return true;
    }
    
    
    for(int i=0;i<n;i++){
        if(edges[s][i]==1 && !visited[i]){
            visited[i]=true;
            bool temp = hasPath(edges,i,e,n,visited);
            if(temp==true)
                return true;
        }
         
    }
    return false;
    
}





int main() {
    int n, E;
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
    
    bool ans = hasPath(edges,s,e,n,visited);
    if(ans==1)
        cout<<"true";
    else
        cout<<"false";
    
    

  return 0;
}
*/