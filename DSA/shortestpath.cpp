#include<bits/stdc++.h>
using namespace std;
const int v=7;
void addEdge(vector<pair<int,int>> graph[],int source,pair<int,int> neighbour){
    graph[source].push_back(neighbour);
}
void toposortutil(vector<pair<int,int>> graph[],int curr,bool vis[],stack<int> &s){
    if(vis[curr]==false){
        vis[curr]=true;
    for(auto neighbour:graph[curr]){
            toposortutil(graph,neighbour.first,vis,s);
    }
    s.push(curr);
}
}
void shortestpath(vector<pair<int,int>> graph[],int source){
    int i=0;
    bool vis[v]={false};
    stack<int> s;
    while(i<v){
        if(vis[i]==false){
        toposortutil(graph,i,vis,s);
    }
    i++;
    }
      int dist[v]={100,100,100,100,100,100,100};
      dist[source]=0;
      while(!s.empty()){
        int curr=s.top();
        s.pop();
        for(auto neighbour:graph[curr]){
            if (dist[curr]+neighbour.second<dist[neighbour.first]){
                  dist[neighbour.first]=dist[curr]+neighbour.second;
            }
        }
      }
      for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
      }
}
int main(){
    vector<pair<int,int>> graph[v];
    
    addEdge(graph,0,{1,2});
    addEdge(graph,1,{3,1});
    addEdge(graph,2,{3,3});
    addEdge(graph,4,{0,3});
    addEdge(graph,4,{2,1});
    addEdge(graph,5,{4,1});
    addEdge(graph,6,{4,2});
    addEdge(graph,6,{5,3});

    shortestpath(graph,6);
    return 0;
}