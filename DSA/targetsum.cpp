#include<bits/stdc++.h>
using namespace std;
int countofsubsetssum(int arr[],int sum,int size){
    int dp[size+1][sum+1];
    for(int i=0;i<size+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1;i<size+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[size][sum];
}
int targetsum(int arr[],int size,int sum){
    int range=0;
    for(int i=0;i<size;i++){
        range+=arr[i];
    }
    int sum2=(range-sum)/2;
    int result=countofsubsetssum(arr,sum2,4);
    return result;
}
int main(){
    int arr[4]={1,1,2,3};
    cout<<targetsum(arr,4,1);
    return 0;
}