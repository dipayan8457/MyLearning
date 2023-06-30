#include<bits/stdc++.h>
using namespace std;
const int v=8;
void addEdge(vector<int> graph[],int source,int destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}
void bipartite(vector<int> graph[]){
    int col[8]={-1,-1,-1,-1,-1,-1,-1,-1};
    queue<int> q;
    col[0]=0;
    q.push(0);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(col[neighbour]==-1){
                q.push(neighbour);
                col[neighbour]=!col[curr];
            }
            else if(col[neighbour]==col[curr]){
                cout<<"Not bipartite";
                return;
            }
        }
    }
    cout<<"Bipartite";
    
}
int main(){
    vector<int> graph[v];
     
     addEdge(graph,0,1);
     addEdge(graph,1,2);
     addEdge(graph,1,5);
     addEdge(graph,3,2);
     addEdge(graph,3,4);
     addEdge(graph,3,6);
     addEdge(graph,4,5);
     addEdge(graph,6,7);
     
     bipartite(graph);
     return 0;
}