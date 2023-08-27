#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isLeaf(struct TreeNode* node)
{
    if (node == NULL)
        return true;

    if (node->left == NULL && node->right == NULL)
        return true;

    return false;
}

void push(struct TreeNode** root, int num)
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = num;
    
    if (isLeaf(root))
    {
        root = newNode;
        return;
    }

    struct TreeNode* curr = root;

    while (isLeaf(curr) != true)
    {
        if (num < curr->val)
        {
            curr = curr->left;
        }

        if (num > curr->val)
        {
            curr = curr->right;
        }
    }
    
    if (num <= curr->val)
    {
        curr->left = newNode;
    }
    else
    {
        curr->right = newNode;
    }
}

int findSecondMinimumValue(struct TreeNode* root)
{
    int secMinValue = 999999;

    if (root->left != NULL)
        findSecondMinimumValue(root->left);
    
    if (root->right != NULL)
        findSecondMinimumValue(root->right);

    if (root->val < secMinValue)
    {
        secMinValue = root->val;
        return secMinValue;
    }

    return -1;
}

int main()
{
    struct TreeNode* root = NULL;

    push(&root, 2);
    push(&root, 2);
    push(&root, 5);
    push(&root, 5);
    push(&root, 7);
    push(&root, 6);
}