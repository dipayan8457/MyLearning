#include<bits/stdc++.h>
using namespace std;
const int v=6;
int main(){
    int start[v]={1,3,0,5,8,5};
    int end[v]={2,4,6,7,9,9};
    vector<int> activities;
    activities.push_back(0);
    int last=0;
    for(int i=1;i<v;i++){
        if(start[i]>=end[last]){
            activities.push_back(i);
            last=i;
        }
    }
    cout<<activities.size()<<" "<<endl;
    for(int i=0;i<activities.size();i++){
        cout<<"A"<<activities[i]<<" ";
    }
    return 0;
    }
