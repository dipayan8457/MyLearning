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
void inorder(struct node* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
int kthsmallest(struct node* root,int k){
    vector<int> v;
    inorder(root,v);
    return v[k-1];
}
int main(){
    struct node* root=new node(10);
    root->left=new node(5);
    root->right=new node(13);
    root->left->left=new node(3);
    root->left->right=new node(6);
    root->right->left=new node(11);
    root->right->right=new node(15);
    root->left->left->left=new node(2);
    root->left->left->right=new node(4);
    root->left->right->right=new node(7);
    root->left->right->right->right=new node(9);

    cout<<kthsmallest(root,4);
    return 0;
}