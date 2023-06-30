#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void nodesdowntarget(struct node* root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    nodesdowntarget(root->left,k-1);
    nodesdowntarget(root->right,k-1);
}
int nodesatk(struct node* root,struct node* target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        nodesdowntarget(root,k);
        return 0;
    }
    int dl=nodesatk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            nodesdowntarget(root->right,k-dl-2);
        }
        return dl+1;
    }
    int dr=nodesatk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            nodesdowntarget(root->left,k-dr-2);
        }
        return dr+1;
    }
    return -1;
}
int main(){
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->left->left->left=new node(8);
    root->left->left->right=new node(9);
    root->left->right->left=new node(10);
    root->left->right->right=new node(11);

    nodesatk(root,root->left,2);
    return 0;

}