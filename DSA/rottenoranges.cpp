#include<bits/stdc++.h>
using namespace std;
int timetorot(vector<vector<int>> basket){
    queue<pair<int,pair<int,int>>> q;
    for(int i=0;i<basket.size();i++){
        for(int j=0;j<basket[i].size();j++){
            if(basket[i][j]==2){
                q.push({0,{i,j}});
            }
        }
    }
    int time=0;
    while(!q.empty()){
        pair<int,pair<int,int>> curr=q.front();
        q.pop();
        if(curr.first>time){
            time=curr.first;
        }
        if(curr.second.first-1>0){//up
           if(basket[curr.second.first-1][curr.second.second]==1){
            basket[curr.second.first-1][curr.second.second]=2;
            q.push({curr.first+1,{curr.second.first-1,curr.second.second}});
           }
        }
        if(curr.second.first+1<basket.size()){//down 
           if(basket[curr.second.first+1][curr.second.second]==1){
            basket[curr.second.first+1][curr.second.second]=2;
            q.push({curr.first+1,{curr.second.first+1,curr.second.second}});
           }
        }
        if(curr.second.second+1<basket[curr.second.first].size()){//right 
           if(basket[curr.second.first][curr.second.second+1]==1){
            basket[curr.second.first][curr.second.second+1]=2;
            q.push({curr.first+1,{curr.second.first,curr.second.second+1}});
           }
        }
        if(curr.second.second-1>0){//left
           if(basket[curr.second.first][curr.second.second-1]==1){
            basket[curr.second.first][curr.second.second-1]=2;
            q.push({curr.first+1,{curr.second.first,curr.second.second-1}});
           }
        }
    }
    return time;
}
int main(){
    vector<vector<int>> basket={{0,1,2},{0,1,1},{2,1,1}};
    cout<<timetorot(basket);
    return 0;
}