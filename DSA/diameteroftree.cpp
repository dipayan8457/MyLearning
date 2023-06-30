#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int height(struct node* root,int& diameter){
    if(root==NULL){
        return 0;
    }
    int a=height(root->left,diameter);
    int b=height(root->right,diameter);
    diameter=max(diameter,a+b);
    return 1+max(a,b);
}
int main(){
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int diameter=0;
    height(root,diameter);
    cout<<diameter;
    return 0;
}