#include<bits/stdc++.h>
using namespace std;
const int v=6;

void addEdge(vector<int> graph[],int source,int destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}
void dfs(vector<int> graph[],int curr,bool vis[]){
    if(vis[curr]==false){
        cout<<curr<<" ";
        vis[curr]=true;
        for(int neighbour:graph[curr]){
            dfs(graph,neighbour,vis);
        }
    }
    else{
        return;
    }
}
    
int main(){
    vector<int> graph[v]; //Declaring a graph 
    addEdge(graph,0,1);
    addEdge(graph,0,5);
    addEdge(graph,1,2);
    addEdge(graph,1,5);
    addEdge(graph,2,4);
    addEdge(graph,3,4);
    addEdge(graph,3,5);

    bool vis[v]={false};
    dfs(graph,0,vis);
    return 0;  
}