/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isLeaf(struct TreeNode* node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return true;
    }

    return false;
}

void flatten(struct TreeNode* root){
    if (root == NULL)
    {
        return;
    }

    if (isLeaf(root))
    {
        return;
    }
    
    struct TreeNode* auxNode = root->right;

    flatten(root->left);
    flatten(root->right);

    root->right = root->left;
    root->left = NULL;

    while(root->right != NULL)
    {
        root = root->right;
    }

    root->right = auxNode;
}