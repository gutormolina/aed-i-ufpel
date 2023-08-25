#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root){
    struct TreeNode* aux;

    if (root != NULL) 
    {
        aux = root->left;    
        root->left = root->right;
        root->right = aux;
        invertTree(root->left);
        invertTree(root->right);
    }
    
    return root;
}