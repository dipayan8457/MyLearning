#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int arr[],int sum,int size){
    bool dp[5][12];
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
int minimumsubsetsumdifference(int arr[],int size){
    int range=0;
    for(int i=0;i<size;i++){
        range+=arr[i];
    }
    int result=range;
    for(int j=0;j<range/2+1;j++){
        if(subsetsum(arr,j,size)==true){
            result=min(result,range-2*j);
        }
    }
    return result;
}
int main(){
    int arr[4]={1,6,11,5};
    cout<<minimumsubsetsumdifference(arr,4);
    return 0;
}