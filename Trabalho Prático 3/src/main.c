#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isLeaf(struct TreeNode *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return true;
    }

    return false;
}

struct TreeNode* push(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findSecondMinimumValue(struct TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    if (isLeaf(root))
    {
        return -1;
    }

    int left = root->left->val,
        right = root->right->val;

    if (root->left->val == root->val)
    {
        left = findSecondMinimumValue(root->left);
    }

    if (root->right->val == root->val)
    {
        right = findSecondMinimumValue(root->right);
    }

    if (left != -1 && right != -1)
    {
        if (left < right)
        {
            return left;
        }

        if (left > right)
        {
            return right;
        }
    }

    if (left != -1)
    {
        return left;
    }

    return right;
}

void clear(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    clear(root->left);
    clear(root->right);
    free(root);
}

int main()
{
    struct TreeNode *r1 = NULL;
    struct TreeNode *r2 = NULL;
    struct TreeNode *r3 = NULL;

    r1 = push(2);
    r1->left = push(2);
    r1->right = push(5);
    r1->right->left = push(5);
    r1->right->right = push(7);

    r2 = push(2);
    r2->left = push(2);
    r2->right = push(2);

    r3 = push(5);
    r3->left = push(8);
    r3->right = push(5);

    printf("\n\tTeste 1: %d\n", findSecondMinimumValue(r1));
    printf("\n\tTeste 2: %d\n", findSecondMinimumValue(r2));
    printf("\n\tTeste 3: %d\n", findSecondMinimumValue(r3));

    clear(r1);
    clear(r2);
    clear(r3);
}