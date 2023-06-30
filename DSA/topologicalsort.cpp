#include<bits/stdc++.h>
using namespace std;
const int v=6;

void addEdge(vector<int> graph[],int source,int destination){
    graph[source].push_back(destination);
}
void toposortutil(vector<int> graph[],int curr,bool vis[],stack<int> &s){
    if(vis[curr]==false){
        vis[curr]=true;
    for(auto neighbour:graph[curr]){
            toposortutil(graph,neighbour,vis,s);
    }
    s.push(curr);
}
}
void topologicalsort(vector<int> graph[]){
    int i=0;
    bool vis[v]={false};
    stack<int> s;
    while(i<v){
        if(vis[i]==false){
        toposortutil(graph,i,vis,s);
    }
    i++;
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main() {
    vector<int> graph[v];

    addEdge(graph,2,3);
    addEdge(graph,3,1);
    addEdge(graph,4,0);
    addEdge(graph,4,1);
    addEdge(graph,5,0);
    addEdge(graph,5,2);

    topologicalsort(graph);
    return 0;
    

}