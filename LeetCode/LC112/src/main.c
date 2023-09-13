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

bool pathSum(struct TreeNode* root, int targetSum, int sum)
{
    if (root == NULL)
    {
        return false;
    }

    sum += root->val;

    if (isLeaf(root) && sum == targetSum)
    {
        return true;
    }

    return (pathSum(root->left, targetSum, sum) ||
            pathSum(root->right, targetSum, sum));    
}

bool hasPathSum(struct TreeNode* root, int targetSum)
{
    return pathSum(root, targetSum, 0);
}