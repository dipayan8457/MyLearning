#include<bits/stdc++.h>
using namespace std;
void combinationsum(int arr[],int ind,int target,vector<int> v){
    if(target==0){
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=ind;i<5;i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
            v.push_back(arr[i]);
            combinationsum(arr,i+1,target-arr[i],v);
            v.pop_back();
        
    }
}
int main(){
    int arr[5]={1,1,1,2,2};
    vector<int> v;
    combinationsum(arr,0,4,v);
    return 0;
}