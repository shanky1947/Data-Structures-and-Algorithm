/*
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2

*/

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void getpath(int V,int **mat,bool *visited,int si,vector<int> &temp){
  	visited[si]=true;
    temp.push_back(si);
	for(int i=0;i<V;i++){
        if(!visited[i]  && mat[si][i]==1){
            getpath( V, mat, visited, i, temp);
        }
    }
}

void print(int V,int **mat){
    bool *visited=new bool[V];
	for(int i=0;i<V;i++)
        visited[i]=false;
    
    vector<int> temp;
    for(int i=0;i<V;i++){
		if(!visited[i]){
            getpath(V,mat,visited,i,temp);
            sort(temp.begin(),temp.end());
            for(int j=0;j!=temp.size();j++)
                cout<<temp[j]<<" ";
        	cout<<endl;
            temp.clear();
        }
    }
}

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
    int a,b;
    for(int i=0;i<E;i++){
        cin>>a>>b;
        mat[a][b]=1;
        mat[b][a]=1;
    }
	print(V,mat);

  return 0;
}

/*
#include <iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;





    
vector<int> add(int**edges,int n,int sv,bool*visited){
    vector<int> v;
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
     // cout<<edges[5][2];
    while(!q.empty()){
        
        for(int i=0;i<n;i++){
            if(edges[q.front()][i]==1 && !visited[i]){
                 q.push(i);
                visited[i]=true;
                 // cout<<i<<"hi"<<endl;
            }
            // 
        }
      
        // cout<<q.front()<<" ";
        v.push_back(q.front());
        
        q.pop();
       
    }
    return v;
    
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
    
    
    vector<vector<int>> big;
    
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> temp = add(edges,v,i,visited);
            sort(temp.begin(),temp.end());
			big.push_back(temp);
        }
    }
    
for(int i=0;i<big.size();i++){
    for(int j=0;j<big.at(i).size();j++){
        cout<<big.at(i).at(j)<<" ";
    }
    cout<<endl;
}
    
    
  return 0;
}
*/