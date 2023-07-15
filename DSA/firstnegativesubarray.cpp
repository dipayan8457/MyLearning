#include<bits/stdc++.h>
using namespace std;
int firstnegative(vector<int> &v,int size){
    int lp=0;
    int rp=0;
    queue<int> q;
    while(rp<v.size()){
        if(v[rp]<0){
                q.push(v[rp]);
            }
        if(rp-lp+1<size){
            rp++;
        }
        else if(rp-lp+1==size){
            if(q.empty()){
                cout<<0<<" ";
            }
        else{
            cout<<q.front()<<" ";
        }
        if(v[lp]==q.front()){
            q.pop();
        }
        lp++;
        rp++;
        }
    } 
}
int main(){
    vector<int> v={12,-1,-7,8,-15,30,13,28};
    firstnegative(v,3);
    return 0;
}