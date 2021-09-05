/*
Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
  int V, E;
  cin >> V >> E;
    queue<int> pq;
    unordered_map<int, int> map; 
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
    vector<int> v;
    pq.push(si);
    visited[si]=true;
    int f=1;
    while(pq.size()!=0){
        int temp=pq.front();
        pq.pop();
        for(int i=0;i<V;i++){
            if(!visited[i] && mat[temp][i]==1){
                visited[i]=true;
                pq.push(i);
                map[i]=temp;
                if(i==ei){
                    f=0;
                    break;
                }
            }
        }
        if(f==0)
            break;
    }
    if(f==1)
        return 0;
    cout<<ei<<" ";
    while(true){
        cout<<map[ei]<<" ";
        ei=map[ei];
        if(ei==si)
       		break;
    }
    return 0;
}
    

    /*
    #include <iostream>
#include<unordered_map>
#include<queue>

using namespace std;




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
    
    unordered_map<int,int> map;
    
    queue<int> q;
    q.push(s);
    visited[s]=true;
    
    
    while(!q.empty()){
        
        for(int i=0;i<n;i++){
            if(edges[q.front()][i]==1 && !visited[i]){
                 q.push(i);
                visited[i]=true;
                map[i]=q.front();
                 // cout<<i<<"hi"<<endl;
                if(i==e)
                    break;
            }
            // 
        }        
        q.pop();
       
    }
    
    if(map.count(e)==0){
        return 0;
    }
    int i=e;
    // cout<<"hi"<<s<<endl;
    while(map[i]!=s){
        cout<<i<<" ";
        i=map[i];
    }
    cout<<i<<" "<<s;
//     vector<int> a = getPath(edges,s,e,n,visited);
    
//     for(int i=0;i<a.size();i++){
//         cout<<a.at(i)<<" ";
//     }
  return 0;
}*/