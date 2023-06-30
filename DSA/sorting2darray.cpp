#include<bits/stdc++.h>
using namespace std;
struct interval{
    int index;
    int start;
    int end;
};
bool sortcol(interval i1,interval i2){
    return (i1.end<i2.end);
}
int main(){
    vector<interval> v={{0,0,6},{1,5,7},{2,3,4},{3,8,9},{4,1,2},{5,5,9}};
    sort(v.begin(),v.end(),sortcol);
    for(int i=0;i<v.size();i++){
        cout<<v[i].index<<" "<<v[i].start<<" "<<v[i].end<<endl;
    }
    return 0;
}