#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int num;
    struct Node *left;
    struct Node *right;
} Node;

Node *create()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    return head;
}

void push(Node *head, int num)
{
    if (head == NULL)
    {
        head->num = num;
        head->left = NULL;
        head->right = NULL;
        return;
    }

    Node *current = head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    newNode->left = NULL;
    newNode->right = NULL;

    while (current != NULL)
    {
        if (num < current->num)
        {
            if (current->left == NULL)
            {
                current->left = newNode;
                return;
            }

            current = current->left;
        }
        else if (num > current->num)
        {
            if (current->right == NULL)
            {
                current->right = newNode;
                return;
            }

            current = current->right;
        }
    }

    current = newNode;
}

void search(Node *head, int num)
{
    if (head == NULL)
    {
        printf("\nEmpty tree!\n");
        return;
    }

    Node *current = head;
    if (current->num = num)
    {
        printf("\nNumber found!\n");
        return;
    }

    while (current != NULL)
    {
        if (num < current->num)
        {
            if (current->left->num == num)
            {
                printf("Number found");
                return;
            }

            current = current->left;
        }
        else if (num > current->num)
        {
            if (current->right->num == num)
            {
                printf("Number found");
                return;
            }

            current = current->right;
        }
    }

    printf("Number isn't present on the tree");
    return;
}

int main()
{
    int num[] = {1, 3, 6, 2, 8, 9, 0, 5, 7};

    Node *head = create();

    push(head, num[0]);
    push(head, num[1]);
    push(head, num[2]);
    push(head, num[3]);
    push(head, num[4]);
    push(head, num[5]);
    push(head, num[6]);
    push(head, num[7]);
    push(head, num[8]);

    search(head, 12);
    search(head, 1);
    search(head, 9);
    search(head, 7);
    search(head, 4);

    return 0;
}
