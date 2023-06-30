#include<bits/stdc++.h>
using namespace std;
void subsequences(int arr[],int size,int index,vector<int> &v){
    if(index==size){
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    v.push_back(arr[index]);
    subsequences(arr,size,index+1,v);
    v.pop_back();
    subsequences(arr,size,index+1,v);
}
int main(){
    int arr[3]={3,1,2};
    vector<int> v;
    subsequences(arr,3,0,v);
}