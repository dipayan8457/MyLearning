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
void ceil(struct node* root,int key,int val){
    if(root==NULL){
         cout<<val;
         return;
    }
    if(key<root->data){
        val=root->data;
        ceil(root->left,key,val);
    }
    if(key>root->data){
        ceil(root->right,key,val);
    }
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
    root->left->left->left=new node(4);
    root->left->right->right=new node(7);
    root->left->right->right->right=new node(9);

    ceil(root,4,-1);
    return 0;
}