#include<bits/stdc++.h>
using namespace std;
const int v=6;
const int infinite=INT_MAX;
void shortestpath(vector<pair<pair<int,int>,int>> &graph,int source){
    int dist[v];
    for(int i=0;i<v;i++){
        dist[i]=infinite;
    }
    dist[0]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<graph.size();j++){
            if(dist[graph[j].first.first]!=infinite && dist[graph[j].first.first]+graph[j].second<dist[graph[j].first.second]){
                dist[graph[j].first.second]=dist[graph[j].first.first]+graph[j].second;
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
    }
}
void addEdge(vector<pair<pair<int,int>,int>> &graph,int source,int destination,int weight){
    graph.push_back({{source,destination},weight});
}
int main() {
    vector<pair<pair<int,int>,int>> graph;
    
    addEdge(graph,0,1,5);
    addEdge(graph,1,2,-2);
    addEdge(graph,1,5,-3);
    addEdge(graph,2,4,3);
    addEdge(graph,3,2,6);
    addEdge(graph,3,4,-2);
    addEdge(graph,5,3,1);

    shortestpath(graph,0);
    
    return 0;
}