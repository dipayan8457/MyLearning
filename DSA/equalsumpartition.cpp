#include<bits/stdc++.h>
using namespace std;
bool equalsumpartition(int arr[],int size){
    int dp[100][100];
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            for(int i=0;i<size+1;i++){
        for(int j=0;j<(sum/2)+1;j++){
            if(i==0){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<size+1;i++){
        for(int j=1;j<(sum/2)+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[size][sum/2];
        }
}
int main(){
    int arr[4]={1,5,11,5};
    cout<<equalsumpartition(arr,4);
    return 0;
}