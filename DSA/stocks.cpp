#include<iostream>
#include<algorithm>
using namespace std;
int stocks(int arr[],int length){
    int* rightmax=new int(length);
    int* profit=new int(length);
    int maxProfit;
    rightmax[length-1]=arr[length-1];
    profit[length-1]=0;
    for(int i=length-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],arr[i]);
        profit[i]=max(rightmax[i+1],arr[i])-arr[i];
        maxProfit=max(profit[i+1],profit[i]); 
    }
    return maxProfit;
}
int main(){
    int arr[]={7,1,5,3,6,4};
    cout<<stocks(arr,6);
    return 0;
}