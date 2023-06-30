#include<iostream>
using namespace std;
int check(int arr[],int n,int curr){
        if(n==0)
        return -1;
        else
        for(int i=0;i<n;i++)
        {
            if(curr==arr[i])
            return i;
        }
        return -1;
    }
int main()
{
    int n=7;
    int arr[]={1,2,5,4,3,5,6};
    int i=0;
    while(i<n){
        int curr=arr[i];
        int flag=check(arr,i,curr);
        if (flag!=-1)
        {
        cout<<flag;
        break;
        }
        i++;
    }   
    return 0;
        }