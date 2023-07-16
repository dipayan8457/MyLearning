#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &val,vector<int> &wt,int maxweight,int items){
    if(items==0 || maxweight==0){
        return 0;
    }
    if(wt[items-1]<=maxweight){
        return max((val[items-1]+knapsack(val,wt,maxweight-wt[items-1],items-1)),knapsack(val,wt,maxweight,items-1));
    }
    else if(wt[items-1]>maxweight){
    return knapsack(val,wt,maxweight,items-1);
    }
}
int main(){
    vector<int> val={1,4,5,7};
    vector<int> wt={1,3,4,7};
    cout<<knapsack(val,wt,8,val.size());
    return 0;
}