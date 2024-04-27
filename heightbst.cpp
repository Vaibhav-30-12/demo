#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node* min(node* head){
        node* node=head;
        while(node->left!=nullptr){
            node= node->left;
            }
            int data= node->data;
            cout<<node->data;
            return node;

    }

};

int height(node* node){
    if(node==nullptr){
        return 0;
    }

    else{
        int left=height(node->left);
        int right=height(node->right);
        return 1+max(left,right);
    }

    
    

}