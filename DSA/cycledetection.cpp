#include<bits/stdc++.h>
using namespace std;
const int v=8;
void addEdge(vector<int> graph[],int source,int destination){
    graph[source].push_back(destination);
}
void dfs(vector<int> graph[],bool vis[],queue<int> q,int curr,int parent){
    if(vis[curr]==false){
        q.push(parent);
        vis[curr]=true;
        for(int neighbour:graph[curr]){
            dfs(graph,vis,q,neighbour,curr);
        }
    }
    else{
        if(curr==q.back()){
            return;
        }
        else{
           cout<<"Cycle detected"<<endl ;
        }
    }
}
void cycledetect(vector<int> graph[],bool vis[]){
    queue<int> q;
    for(int i=0;i<v;i++){
        if(vis[i]==false){
        dfs(graph,vis,q,i,-1);
        }
    }
}                                  
int main(){
    vector<int> graph[v];
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,0);
    addEdge(graph,0,3);
    addEdge(graph,2,4);

    bool vis[v]={false};
    cycledetect(graph,vis);
}