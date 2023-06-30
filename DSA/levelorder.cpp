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
void levelorder(struct node* root,queue<struct node*> q){

    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        if(curr!=NULL){
            cout<<curr->data<<" ";
            if(curr->left){
            q.push(curr->left);
            }
            if(curr->right){
            q.push(curr->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }

}
int main(){
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    queue<struct node*> q;
    q.push(root);
    levelorder(root,q);

    return 0;
}