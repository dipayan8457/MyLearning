#include<bits/stdc++.h>
using namespace std;
const int v=6;
const int infinite=INT_MAX;
void shortestpath(vector<pair<int,int>> graph[],int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int dist[v];
    for(int i=0;i<v;i++){
          dist[i]=infinite;
    }
    dist[source]=0;
    q.push({dist[source],source});
    while(!q.empty()){
    pair<int,int> curr=q.top();
    for(auto neighbour:graph[curr.second]){
           if(dist[curr.second]+neighbour.second<dist[neighbour.first]){
                dist[neighbour.first]=dist[curr.second]+neighbour.second;
                q.push({dist[neighbour.first],neighbour.first});
           }
    }
    q.pop();
    }
    for(int j=0;j<v;j++){
        cout<<dist[j]<<" ";
    }
}
void addEdge(vector<pair<int,int>> graph[],int source,pair<int,int> destination){
    graph[source].push_back(destination);
    graph[destination.first].push_back({source,destination.second});
}
int main(){
    vector<pair<int,int>> graph[v];

    addEdge(graph,0,{1,4});
    addEdge(graph,0,{2,4});
    addEdge(graph,1,{2,2});
    addEdge(graph,2,{3,3});
    addEdge(graph,2,{4,1});
    addEdge(graph,2,{5,6});
    addEdge(graph,3,{5,2});
    addEdge(graph,4,{5,3});

    shortestpath(graph,0);
    return 0;
}