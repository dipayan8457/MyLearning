#include<bits/stdc++.h>
using namespace std;
const int v=7;
void addEdge(vector<int> graph[],int source,int destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}
void print(vector<int> path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void sourcetotarget(vector<int> graph[],vector<int> path,bool vis[],int curr,int target){
    if(curr!=target){
        if(vis[curr]==false){
            vis[curr]=true;
            path.push_back(curr);
            for(int neighbour:graph[curr]){
                sourcetotarget(graph,path,vis,neighbour,target);
            }
            vis[curr]=false;
            path.pop_back();
        }
        else{
            return;
        } 
    }
    else{
        path.push_back(curr);
        print(path);
    }
}
int main(){
    vector<int> graph[v];
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,2,4);
    addEdge(graph,3,4);
    addEdge(graph,3,5);
    addEdge(graph,4,5);
    addEdge(graph,5,6);

    bool vis[v]={false};
    vector<int> path;
    sourcetotarget(graph,path,vis,0,5);
    return 0;
    
}