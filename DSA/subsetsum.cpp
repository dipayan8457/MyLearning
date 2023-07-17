#include<bits/stdc++.h>
using namespace std;
const int maxsize=10;
const int maxsum=100;
bool subsetsum(int arr[],int sum,int size){
    bool static dp[maxsize+1][maxsum+1];
    for(int i=0;i<size+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<size+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[size][sum];
}
int main(){
    int arr[5]={2,3,5,6,8};
    cout<<subsetsum(arr,14,5);
    return 0;
}