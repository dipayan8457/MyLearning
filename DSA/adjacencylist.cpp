#include<bits/stdc++.h>
using namespace std;
const int v=6;

void addEdge(vector<int> graph[],int source,int destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}

void printGraph(vector<int> graph[]){
    for(int source=0;source<v;source++){
        cout<<"There are "<<graph[source].size()<<" neighbours of "<<source<<endl;
        for(int neighbour:graph[source]){
            cout<<"There is an EDGE between: "<<source<<" and "<<neighbour<<endl;
        }
        cout<<endl;
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

    printGraph(graph);
}