#include<iostream>
using namespace std;

// defining an AVL tree class
class AVLtree
{
    public:
    // key for value of the node
    int key;
    // left for the left child
    AVLtree *left;
    // right for the right child
    AVLtree *right;
    // height for telling the hright of the node
    int height;
    // constructor
    AVLtree(){
        left=NULL;
        right=NULL;
        height=1;
    }
};

// to find max of two integers
int max(int a, int b)
{
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

// a function to get height of the tree using its own class object
int getHeight(AVLtree *tree)
{
    if (tree == NULL) {return 0;}
    return tree->height;
}

// initialising a new node in AVL tree by a key value
AVLtree* new_node(int key)
{
    AVLtree* tree = new AVLtree();
    tree->key = key;
    return(tree);
}

// at time of Left rotate operation
AVLtree *leftRotate(AVLtree *treeNode)
{
    AVLtree *current = treeNode->right;
    AVLtree *t2 = current->left;
 
    current->left = treeNode;
    treeNode->right = t2;

    // since height can change during rotation for a node thus we have to keep a check
    treeNode->height = max(getHeight(treeNode->left),getHeight(treeNode->right)) + 1;
    current->height = max(getHeight(current->left),getHeight(current->right)) + 1; 

    // returning new node at the place of the old node coming at the top
    return current;
}

// at time of right rotate operation
AVLtree *rightRotate(AVLtree *treenode)
{
    AVLtree *curr = treenode->left;
    AVLtree *t2 = curr->right;
 
    curr->right = treenode;
    treenode->left = t2;

    // since height can change during rotation for a node thus we have to keep a check
    treenode->height = max(getHeight(treenode->left), getHeight(treenode->right)) + 1;
    curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;

    // returning new node at the place of the old node coming at the top 
    return curr;
}

// balanceFactor needs to be calculated for every node
int getBalance(AVLtree *tree)
{
    if (tree == NULL){
        return 0;}
    int bF = getHeight(tree->left) - getHeight(tree->right);
    return bF;
}

// inserting a node: main code
AVLtree* insertNode(AVLtree* tree, int key)
{
    // edge case
    if (tree == NULL){
        return(new_node(key));
    }

    // key mmust go on the left
    if (key < tree->key){
        tree->left = insertNode(tree->left, key);
    }
    // key must go on the right
    else if (key > tree->key){
        tree->right = insertNode(tree->right, key);
    }
    // key equals the root
    else{ 
        return tree;
    }
    tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));

    // on basis of balance factor                 
    int balance = getBalance(tree);

    // key < child
    if (balance < -1 && key > tree->right->key){        
        return leftRotate(tree);
    }
    if (balance > 1 && key < tree->left->key)
            return rightRotate(tree);

    // key > child
    if (balance > 1 && key > tree->left->key)
    {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }
    if (balance < -1 && key < tree->right->key)
    {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }

    return tree;
}

void preOrder(AVLtree *root)
{   if(root==NULL){
    return;
    }
    cout<<root->key<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
 
int main()
{
    AVLtree *tree = NULL;
    tree = insertNode(tree, 10);
    tree = insertNode(tree, 20);
    tree = insertNode(tree, 50);
    tree = insertNode(tree, 35);
    tree = insertNode(tree, 26);    
    cout << "The preorder of the tree is: "<<endl;
    preOrder(tree);
    return 0;
}