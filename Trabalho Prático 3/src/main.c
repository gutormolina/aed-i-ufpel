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

void push(struct TreeNode **root, int num)
{
    struct TreeNode *current = *root;
    struct TreeNode *previous = NULL;
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = num;
    newNode->left = NULL;
    newNode->right = NULL;

    if (current == NULL)
    {
        *root = newNode;
        return;
    }

    while (current != NULL)
    {
        previous = current;
        if (num <= current->val)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (newNode->val <= previous->val && newNode->val != previous->left->val)
    {
        previous->left = newNode;
    }
    else
    {
        previous->right = newNode;
    }
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

    push(&r1, 2);
    push(&r1, 2);
    push(&r1, 5);
    push(&r1, 5);
    push(&r1, 7);

    push(&r2, 2);
    push(&r2, 2);
    push(&r2, 2);

    printf("\n\tTeste 1: %d\n", findSecondMinimumValue(r1));
    printf("\n\tTeste 2: %d\n", findSecondMinimumValue(r2));
}