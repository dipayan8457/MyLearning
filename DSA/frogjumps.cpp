#include<bits/stdc++.h>
using namespace std;
int minenergy(int arr[],int index){
    if(index==0){
        return 0;
    }
    int min1=minenergy(arr,index-1)+abs(arr[index]-arr[index-1]);
    if(index>1){
    int min2=minenergy(arr,index-2)+abs(arr[index]-arr[index-2]);
    return min(min1,min2);
    }
    return min1;
}
int main(){
    int arr[4]={10,20,30,10};
    cout<<minenergy(arr,3);
    return 0;
}