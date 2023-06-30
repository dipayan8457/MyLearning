#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int start,int end,int mid){
    vector<int> temp;
    int ptr1=start;
    int ptr2=mid+1;
    while(ptr1<=mid && ptr2<=end){
         if(arr[ptr1]<arr[ptr2]){
            temp.push_back(arr[ptr1]);
            ptr1++;
         }
         else{
            temp.push_back(arr[ptr2]);
            ptr2++;
         }
    }
    while(ptr1<=mid){
        temp.push_back(arr[ptr1]);
            ptr1++;
    }
    while(ptr2<=end){
        temp.push_back(arr[ptr2]);
            ptr2++;
    }
    int j=0;
    for(int i=start;i<=end;i++){
        arr[i]=temp[j];
        j++;
    }

}
void mergesort(int arr[],int start,int end){
    if(start==end){
        return;
    }
    int mid=start+(end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,end,mid);

}
int main(){
    int arr[10]={9,3,12,7,5,6,2,15,10,1};
    mergesort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}