#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n){
    int curr=1;
    int prev=0;
    int i=1;
    while(i<n){
         curr=curr+prev;
         prev=curr-prev;
         i++;
    }
    return curr;
}
int main(){
    cout<<fibonacci(6);
    return 0;
}