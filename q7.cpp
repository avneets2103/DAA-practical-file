#include<iostream>
using namespace std;

// making a Binary Tree Node class
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    // constructor
    BinaryTreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

// function to find the height
int height(BinaryTreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(height(root->left),height(root->right));
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    BinaryTreeNode* n1 = new BinaryTreeNode(20);
    BinaryTreeNode* n2 = new BinaryTreeNode(30);
    BinaryTreeNode* n3 = new BinaryTreeNode(40);
    BinaryTreeNode* n4 = new BinaryTreeNode(50);
    BinaryTreeNode* n5 = new BinaryTreeNode(60);
    // connections
    root->left = n1;
    root->right = n2;
    n1->left=n3;
    n3->right=n4;
    n1->right=n5;

    // Tree formed:
    //       10
    //      /  \
    //     20  30
    //    /      \
    //   40      60
    //    \
    //    50

    cout<<"The max height of the given tree is: "<<height(root);
    return 0;
}
