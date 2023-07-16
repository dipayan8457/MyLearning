#include<bits/stdc++.h>
using namespace std;
const int maxitems=4;
const int maxweight=8;
int knapsack(int val[],int wt[],int weight,int items){
    int static dp[maxitems+1][maxweight+1];
    memset(dp,int(-1),sizeof dp);
    if(items==0 || weight==0){
        return 0;
    }
    if(dp[items][weight]!=-1){
        return dp[items][weight];
    }
    if(wt[items-1]<=weight){
        return dp[items][weight]= max((val[items-1]+knapsack(val,wt,weight-wt[items-1],items-1)),knapsack(val,wt,weight,items-1));
    }
    else if(wt[items-1]>weight){
    return dp[items][weight]=knapsack(val,wt,weight,items-1);
    }
}
int main(){
    int val[maxitems]={1,4,5,7};
    int wt[maxitems]={1,3,4,7};
    cout<<knapsack(val,wt,8,4);
    return 0;
}