#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[40];
    float price;
} Item;

typedef struct Node
{
    Item info;
    struct Node *next;
} Node;

typedef struct
{
    Node *first;
    Node *last;
} Queue;

Queue *reset()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->first = NULL;
    queue->last = NULL;

    return queue;
}

void push(Queue *queue, Item item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = item;
    newNode->next = NULL;

    if (queue->first == NULL && queue->last == NULL)
    {
        queue->first = newNode;
        queue->last = newNode;
        return;
    }

    queue->last->next = newNode;
    queue->last = newNode;

    return;
}

void pop(Queue *queue)
{
    if (queue->first == NULL)
    {
        printf("Empty queue!");
        return;
    }

    Node *remove = queue->first;
    queue->first = queue->first->next;

    if (queue->first == NULL)
    {
        queue->last == NULL;
    }

    printf("Removed item: %s\n\n", remove->info.name);
    free(remove);

    return;
}

void printQueue(Queue *queue)
{
    if (queue->first == NULL)
    {
        printf("Empty queue!");
        return;
    }
    
    Node *node = queue->first;

    for (node = queue->first; node != NULL; node = node->next)
    {
        printf("Item: %s\nID: %d\nPrice: %.2f\n\n",
            node->info.name,
            node->info.id,
            node->info.price);
    }

    return;
}

void clear(Queue *queue)
{
    while (queue->first != NULL)
    {
        pop(queue);
    }
    
    free(queue);

    return;
}

int main()
{
    Item i1, i2, i3, i4, i5;
    
    strcpy(i1.name, "Maçã");
    i1.id = 5;
    i1.price = 2.99;

    strcpy(i2.name, "Pão");
    i2.id = 9;
    i2.price = 4.59;

    strcpy(i3.name, "Refrigerante");
    i3.id = 236;
    i3.price = 12.99;

    strcpy(i4.name, "Torta");
    i4.id = 43;
    i4.price = 20.00;

    strcpy(i5.name, "Moletom");
    i5.id = 0;
    i5.price = 79.99;

    Queue *queue = reset();

    push(queue, i1);
    push(queue, i2);
    push(queue, i3);
    push(queue, i4);
    push(queue, i5);

    printQueue(queue);

    pop(queue);

    printQueue(queue);

    clear(queue);
    
    return 0;
}