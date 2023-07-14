#include<bits/stdc++.h>
using namespace std;
int longestcommonsubsequence(string str1,string str2,int ind1,int ind2){
    if(ind1>=str1.length() || ind2>=str2.length()){
        return 0;
    }
    if(str1[ind1]==str2[ind2]){
        return 1+longestcommonsubsequence(str1,str2,ind1+1,ind2+1);
    }
    if(str1[ind1]!=str2[ind2]){
        return max(longestcommonsubsequence(str1,str2,ind1+1,ind2),longestcommonsubsequence(str1,str2,ind1,ind2+1));
    }
}
int main(){
    string str1="adcbc";
    string str2="dcadb";
    cout<<longestcommonsubsequence(str1,str2,0,0);
    return 0;
}