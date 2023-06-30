#include<bits/stdc++.h>
using namespace std;
void combinationsum(int ind,int arr[],int sum,vector<int> v){
    if(sum<0 || ind>3){
        return;
    }
    if(sum==0){
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    v.push_back(arr[ind]);
    combinationsum(ind,arr,sum-arr[ind],v);
    v.pop_back();
    combinationsum(ind+1,arr,sum,v);
}
int main(){
    int arr[4]={2,3,6,7};
    vector<int> v;
    combinationsum(0,arr,7,v);
}