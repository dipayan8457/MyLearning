#include<bits/stdc++.h>
using namespace std;
int climbingstairs(int arr[],int curr,int target){
     if(arr[curr]==target){
        return 1;
     }
     if(arr[curr]==target-1){
        return 1;
     }
     int a=climbingstairs(arr,curr+1,target);
     int b=climbingstairs(arr,curr+2,target);
     return a+b;
}
int main(){
    int arr[4]={0,1,2,3};
    cout<<climbingstairs(arr,0,3);
    return 0;
}