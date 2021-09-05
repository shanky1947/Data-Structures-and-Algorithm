/*
Code : Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class edge{
public:
    int weight;
    int source;
    int dest;
};

bool compareInterval(edge i1,edge i2){
    return (i1.weight<i2.weight);
}
bool findParent(int v1,int v2,int *parent){
    while(true){
        if(v1==parent[v1])
            break;
        v1=parent[v1];
    }
    while(true){
        if(v2==parent[v2])
            break;
        v2=parent[v2];
    }
    parent[v1]=v2;
    if(v1==v2)
        return true;
    else
        return false;
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
	edge input[E];
	edge output[V-1];
    
    int s,d,w;
    for(int i=0;i<E;i++){
        cin>>s>>d>>w;
        input[i].weight=w;
        input[i].source=s;
        input[i].dest=d;
    }
    sort(input,input+E,compareInterval);
    int *parent=new int[V];
    for(int i=0;i<V;i++)
        parent[i]=i;
    
    int count=0,i=0;
    while(count<V-1){
        int v1=input[i].source, v2=input[i].dest;
        if(findParent(v1,v2,parent)){
            i++;
            continue;
        }
        else{
            output[count].weight=input[i].weight;
            output[count].source=input[i].source;
            output[count].dest=input[i].dest;
            count++;
        }
    }
    for(int i=0;i<count;i++){
        cout<<min(output[i].dest,output[i].source)<<" "<<max(output[i].dest,output[i].source)<<" "<<output[i].weight<<endl;
    }
  return 0;
}


/*include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source,dest,weight;
    
};

bool compare(Edge e1,Edge e2){
    
    return e1.weight<e2.weight;   
}



int findParent(int i,int p[]){
    
   // cout<<"hi";
    
   // cout<<p[0]<<"dd"<<i<<endl;
    
    
    while(p[i]!=i){
        i=p[i];
        //p[i]=i;
    }
    return i;
}

int main()
{
  int n, e;
  cin >> n >> e;

    Edge input[e];
    Edge output[n-1];
    int s,d,w;
    for(int i=0;i<e;i++){
        cin>>s>>d>>w;
        Edge node;
        node.source = s;
        node.dest = d;
        node.weight = w;
         input[i] = node;
        // cout<<input[i].source<<" "<<input[i].dest<<" "<<input[i].weight<<endl;
    }
    
    sort(input,input+e,compare);
    // for(int i=0;i<e;i++){
    //     cout<<input[i].source<<" "<<input[i].dest<<" "<<input[i].weight<<endl;
    // }
    
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
        // cout<<parent[i]<<"hhhhhhh"<<endl;
    }
    int count =0;
  
        for(int i=0;i<e;i++){
            if(count>=n-1){
                break;
            }
            int s1 = input[i].source;
            int e1 = input[i].dest;
            // cout<<s1<<" "<<e1<<endl;
            int p1 = findParent(s1,parent);
            int p2 = findParent(e1,parent);
            // cout<<p1<<" "<<p2<<endl;
            if(p1!=p2){
                output[count] = input[i];
                count++;
                //parent[s1] = e1;
                parent[p1] = p2;
            }
            // cout<<"hi";
        }
    
    for(int i=0;i<n-1;i++){
        cout<<min(output[i].source,output[i].dest)<<" "<<max(output[i].source,output[i].dest)<<" "<<output[i].weight<<endl;
    }
       


  return 0;
}
*/