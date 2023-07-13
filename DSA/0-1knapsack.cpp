#include<bits/stdc++.h>
using namespace std;
const int items=4;
int knapsack(vector<pair<int,int>> v,int constraint,int curr,int profit){
    if(curr==items || constraint==0){
        return profit;
    }
    if(v[curr].first<=constraint){
        int a=knapsack(v,constraint,curr+1,profit);
        int b=knapsack(v,constraint-v[curr].first,curr+1,profit+v[curr].second);
        return max(a,b);
    }
    return knapsack(v,constraint,curr+1,profit);
}
int main(){
    vector<pair<int,int>> v={{1,1},{3,4},{4,5},{5,7}};
    cout<<knapsack(v,7,0,0);
    return 0;
}