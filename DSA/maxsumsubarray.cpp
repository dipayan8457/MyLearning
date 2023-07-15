#include<bits/stdc++.h>
using namespace std;
int maxsumsubarray(vector<int> &v,int size){
    int lp=0;
    int rp=0;
    int sum=0;
    int result=0;
    while(rp<v.size()){
        sum+=v[rp];
        if(rp-lp+1<size){
            rp++;
        }
        else if(rp-lp+1==size){
            result=max(result,sum);
            sum=sum-v[lp];
            lp++;
            rp++;
        }
    }
    return result;
}
int main(){
    vector<int> v={2,5,1,8,2,9,1};
    cout<<maxsumsubarray(v,3);
    return 0;
}