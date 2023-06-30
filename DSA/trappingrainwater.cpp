#include<iostream>
#include<algorithm>
using namespace std;
int trappingrainwater(int arr[],int height){
    int* leftmax=new int[height];
    leftmax[0]=arr[0];
    for(int i=1;i<height;i++){
        leftmax[i]=max(leftmax[i-1],arr[i]);
    }
    int* rightmax=new int[height];
    rightmax[height-1]=arr[height-1];
    for(int i=height-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],arr[i]);
    }
    int count=0;
    for(int i=0;i<height;i++){
        count+=min(leftmax[i],rightmax[i])-arr[i];
    }
    return count;
}

int main(){
    int arr[]={4,2,0,6,3,2,5};
    cout<<trappingrainwater(arr,7);
    return 0;
}