#include<bits/stdc++.h>
using namespace std;
const int v=6;

void addEdge(vector<int> graph[],int source,int destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}
void bfs(vector<int> graph[]){
    queue<int> q;
    int curr=0;
    q.push(curr);
    bool vis[v]={false};
    while(!q.empty()){
        curr=q.front();
        if(vis[curr]==false){
            cout<<curr<<" ";
            vis[curr]=true;
            q.pop();
            for(int neighbour:graph[curr]){
                q.push(neighbour);
            }
        }
        else{
            q.pop();
        }
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

    bfs(graph);
    return 0;  
}