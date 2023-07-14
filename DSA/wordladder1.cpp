#include<bits/stdc++.h>
using namespace std;
int wordladder(vector<string> &wordlist,string startWord,string targetWord){
    unordered_set<string> s(wordlist.begin(),wordlist.end());
    queue<pair<string,int>> q;
    q.push({startWord,0});
    while(!q.empty()){
    string curr=q.front().first;
    int steps=q.front().second;
    q.pop();
    if(curr==targetWord){
        return steps;
    }
    for(int i=0;i<curr.length();i++){
        char letter=curr[i];
        for(char j='a';j<='z';j++){
        curr[i]=j;
        if(s.find(curr)!=s.end()){
            q.push({curr,steps+1});
            s.erase(s.find(curr));
        }
        }
        curr[i]=letter;
    }
    }
}
int main(){
    vector<string> wordlist={"hot","dot","dog","lot","log","cog"};
    cout<<wordladder(wordlist,"hit","cog");
    return 0;
}