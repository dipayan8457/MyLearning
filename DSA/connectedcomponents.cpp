#include<bits/stdc++.h>
using namespace std;
const int v=7;
void addEdge(vector<int> graph[],int source,int destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}
void bfsutil(vector<int> graph[],int curr,bool vis[]){
    queue<int> q;
    q.push(curr);
    while(!q.empty()){
        if(vis[q.front()]==false){
            cout<<q.front()<<" ";
            for(int neighbour:graph[q.front()]){
                q.push(neighbour);
            }
            vis[q.front()]=true;
            q.pop();
        }
        else{
            q.pop();
        }
    }
    cout<<endl;
    }
void bfs(vector<int> graph[],bool vis[]){
    for(int i=0;i<v;i++){
        if(vis[i]==false){
        bfsutil(graph,i,vis);
        }
    }
}
int main(){
    vector<int> graph[v];
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,2,3);
    addEdge(graph,4,5);
    addEdge(graph,5,6);
    
    bool vis[v]={false};
    bfs(graph,vis);
}