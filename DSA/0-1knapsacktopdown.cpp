#include<bits/stdc++.h>
using namespace std;
const int maxitems=4;
const int maxweight=8;
int knapsack(int val[],int wt[],int weight,int items){
    int static dp[maxitems+1][maxweight+1];
    memset(dp,int(-1),sizeof dp);
    for(int i=0;i<items;i++){
        for(int j=0;j<weight;j++){
            if(i==0 || j==0){
            dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<items+1;i++){
        for(int j=1;j<weight+1;j++){
     if(wt[i-1]<=j){
        dp[i][j]= max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
    }
     else if(wt[i-1]>j){
    dp[i][j]=dp[i-1][j];
    }
        }
    }
    return dp[items][weight];
}
int main(){
    int val[maxitems]={1,4,5,7};
    int wt[maxitems]={1,3,4,7};
    cout<<knapsack(val,wt,8,4);
    return 0;
}