#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int num;
    struct Node *left;
    struct Node *right;
} Node;

void push(Node **root, int num)
{
    Node *current = *root;
    Node *previous = NULL;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
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
        if (num < current->num)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (newNode->num < previous->num)
    {
        previous->left = newNode;
    }
    else
    {
        previous->right = newNode;
    }

    
}

void search(Node *node, int num)
{
    if (node == NULL)
    {
        printf("\nNumber isn't present on the tree\n");
        return;
    }

    if (node->num == num)
    {
        printf("\nNumber found!\n");
        return;
    }

    if (num < node->num)
    {
        return search(node->left, num);
    }

    if (num > node->num) {
        return search(node->right, num);
    }
}

void clear(Node *root)
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
    int num[] = {1, 3, 6, 2, 8, 9, 0, 5, 7};

    Node *root = NULL;

    push(&root, num[0]);
    push(&root, num[1]);
    push(&root, num[2]);
    push(&root, num[3]);
    push(&root, num[4]);
    push(&root, num[5]);
    push(&root, num[6]);
    push(&root, num[7]);
    push(&root, num[8]);

    search(root, 12);
    search(root, 1);
    search(root, 9);
    search(root, 7);
    search(root, 4);

    clear(root);

    return 0;
}
