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
void printTree(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}
int search(int arr[],int start,int end,int val){
    int i;
    for(i=start;i<=end;i++){
        if(arr[i]==val){
        break;
        }
        else{
            continue;
        }
    }
    return i;
}
struct node* buildTree(int preorder[],int inorder[],int start,int end){
    if(start>end){
        return NULL;
    }
    static int idx=0;
    int curr=preorder[idx];
    idx++;
    struct node* currnode=new node(curr);
    if(start==end){
        return currnode;
    }
    int pos=search(inorder,start,end,curr);
    currnode->left=buildTree(preorder,inorder,start,pos-1);
    currnode->right=buildTree(preorder,inorder,pos+1,end);
}
int main(){

    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    struct node* root=buildTree(preorder,inorder,0,4);
    printTree(root);
    return 0;

}