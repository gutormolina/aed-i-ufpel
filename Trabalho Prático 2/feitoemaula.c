#include <stdio.h>
#include <stdlib.h>

typedef struct
{   
    int type1;
    int type2;
} Cup;

typedef struct Node
{
    Cup info;
    struct Node *next;
} Node;

typedef struct 
{
    Node *head;
    Node *tail;
} Heap;

Heap *reset() 
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->head = NULL;
    heap->tail = NULL;
    return heap;
}

void push(Heap *heap, Cup cup)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = cup;
    if (heap->head == NULL) 
    {
        heap->head = newNode;
    }
    
    newNode = heap->tail;
    heap->tail = newNode;

}

Cup *pop(Heap *heap)
{

}

void clear(Heap *heap)
{
    while (heap->head->next != NULL)
    {
        
    }
    
    free(heap);
}

int fillCups(int* amount, int amountSize)
{
    Heap *heap = reset();
    while (amount[0] != 0 && amount[1] != 0 && amount[2] != 0) 
    {
        Cup cup;
        if (amount[0] >= amount[1] && amount[0] >= amount[2])
        {
            cup.type1 = 0;
            amount[0]--;
            if (amount[1] >= amount[2])
            {
                cup.type2 = 1;
                amount[1]--;
            } else
            {
                cup.type2 = 2;
                amount[2]--;
            }
        } else if (amount[1] >= amount[0] && amount[1] >= amount[2])
        {
            cup.type1 = 1;
            amount[1]--;
            if (amount[0] >= amount[2])
            {
                cup.type2 = 0;
                amount[0]--;
            } else
            {
                cup.type2 = 2;
                amount[2]--;
            }
        } else
        {
            cup.type1 = 2;
            amount[2]--;
            if (amount[0] >= amount[1])
            {
                cup.type2 = 0;
                amount[0]--;
            } else
            {
                cup.type2 = 1;
                amount[1]--;
            }
        }

        push(heap, cup);
    }

    clear(heap);
}

int main()
{
    int size = 3;
    int *amount[size];
    amount[0] = 1;
    amount[1] = 4;
    amount[2] = 2;
    fillCups(amount, size);
}