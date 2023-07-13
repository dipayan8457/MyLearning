#include<bits/stdc++.h>
using namespace std;
void kclosest(vector<pair<int,int>> &v,int k){
    priority_queue<pair<int,pair<int,int>>> q;
    q.push({pow(v[0].first,2)+pow(v[0].second,2),v[1]});
    int i=0;
    for( i=1;i<v.size();i++){
       q.push({pow(v[i].first,2)+pow(v[i].second,2),v[i]});
       if(q.size()>k){
        q.pop();
       }
    }
    cout<<q.top().second.first<<" "<<q.top().second.second;
}
int main(){
    vector<pair<int,int>> v={{1,3},{-2,2},{5,8},{4,1}};
    kclosest(v,1);
    return 0;
}