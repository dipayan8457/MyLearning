#include<bits/stdc++.h>
using namespace std;
void longestsubarray(string &str){
    set<char> st;
    int lp=0;
    int rp=0;
    int len=0;
    while(lp<str.length() && rp<str.length()){
           if(st.find(str[rp])==st.end()){
            st.insert(str[rp]);
            if(rp-lp+1>len){
                len=rp-lp+1;
            }
            rp++;
           }
           else{
            st.erase(st.find(str[lp]));
            lp++;
           }
    }
    cout<<len;
}
int main(){
    string str="";
    longestsubarray(str);
    return 0;
}