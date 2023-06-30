#include<bits/stdc++.h>
using namespace std;
const int size=5;
const int alphabets=4;
int val(char x){
     if(x=='a'){
        return 0;
     }
     if(x=='b'){
        return 1;
     }
     if(x=='c'){
        return 2;
     }
     if(x=='d'){
        return 3;
     }
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
void alphabetorder(string arr[]){
    vector<int> graph[alphabets];
    for(int i=0;i<size-1;i++){
        int len=min(arr[i].length(),arr[i+1].length());
        for(int ptr=0;ptr<len;ptr++){
            if(arr[i][ptr]!=arr[i+1][ptr]){
                graph[val(arr[i][ptr])].push_back(val(arr[i+1][ptr]));
                break;
            }
        }
    }
    int j=0;
    bool vis[alphabets]={false};
    stack<int> s;
    while(j<alphabets){
        if(vis[j]==false){
        toposortutil(graph,j,vis,s);
    }
    j++;
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main(){
    string arr[size]={"baa","abcd","abca","cab","cad"};
    alphabetorder(arr);
    return 0;
}