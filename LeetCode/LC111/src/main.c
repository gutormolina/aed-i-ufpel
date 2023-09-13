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

int minDepth(struct TreeNode* root)
{
    int left, right;
    if (root == NULL)
    {
        return 0;
    }

    if (isLeaf(root)) {
        return 1;
    }

    if (root->left != NULL)
    {
        left = minDepth(root->left);
    }

    if (root->right != NULL)
    {
        right = minDepth(root->right);
    }

    if (left <= right)
    {
        return 1 + left;
    }

    return 1 + right;
}