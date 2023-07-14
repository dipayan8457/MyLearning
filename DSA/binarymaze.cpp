#include<bits/stdc++.h>
using namespace std;
const int x=5;
const int y=4;
const int infinite=INT_MAX;
int shortestpath(int maze[x][y],pair<int,int> source,pair<int,int> target){
    queue<pair<int,pair<int,int>>> q;
    int dist[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            dist[i][j]=infinite;
        }
    }
    dist[source.first][source.second]=0;
    q.push({dist[source.first][source.second],source});
    while(!q.empty()){
        pair<int,int> curr=q.front().second;
        q.pop();
        if(curr==target){
            return dist[curr.first][curr.second];
        }
        if(curr.first-1>=0){//up
        if(maze[curr.first-1][curr.second]!=0){
           if(dist[curr.first-1][curr.second]>(dist[curr.first][curr.second]+1)){
              dist[curr.first-1][curr.second]=dist[curr.first][curr.second]+1;
              q.push({dist[curr.first-1][curr.second],{curr.first-1,curr.second}});
           }
        }
        }
         if(curr.first+1<=x){//down
         if(maze[curr.first+1][curr.second]!=0){
           if(dist[curr.first+1][curr.second]>(dist[curr.first][curr.second]+1)){
              dist[curr.first+1][curr.second]=dist[curr.first][curr.second]+1;
              q.push({dist[curr.first+1][curr.second],{curr.first+1,curr.second}});
           }
         }
        }
         if(curr.second-1>=0){//left
         if(maze[curr.first][curr.second-1]!=0){
           if(dist[curr.first][curr.second-1]>(dist[curr.first][curr.second]+1)){
              dist[curr.first][curr.second-1]=dist[curr.first][curr.second]+1;
              q.push({dist[curr.first][curr.second-1],{curr.first,curr.second-1}});
           }
         }
        }
         if(curr.second+1<=y){//right
         if(maze[curr.first][curr.second+1]!=0){
           if(dist[curr.first][curr.second+1]>(dist[curr.first][curr.second]+1)){
              dist[curr.first][curr.second+1]=dist[curr.first][curr.second]+1;
              q.push({dist[curr.first][curr.second+1],{curr.first,curr.second+1}});
           }
         }
        }
    }
}
int main(){
    int maze[x][y]={1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,0,0};
    cout<<shortestpath(maze,{0,1},{2,2});
    return 0;
}