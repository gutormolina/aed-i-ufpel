#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[30];
    int age;
} Person;

typedef struct Node
{
    Person info;
    struct Node *next;
} Node;

typedef struct
{
    Node *first;
    Node *last;
} Heap;

Heap *reset()
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->first == NULL;
    heap->last == NULL;

    return heap;
}

void push(Heap *heap, Person person)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = person;
    newNode->next = NULL;

    if (heap->first == NULL || heap->first->info.age <= newNode->info.age)
    {
        newNode->next = heap->first;
        heap->first = newNode;

        if (newNode->next == NULL)
        {
            heap->last = newNode;
        }

        return;
    }

    Node *current = heap->first;
    while (current->next != NULL && newNode->info.age <= current->next->info.age)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    if (newNode->next == NULL)
    {
        heap->last = newNode;
    }
    
    return;
}

void pop(Heap *heap)
{
    if (heap->first == NULL)
    {
        printf("Empty heap!");
        return;
    }

    Node *remove = heap->first;
    heap->first = heap->first->next;

    if (heap->first == NULL)
    {
        heap->last == NULL;
    }

    printf("Removed person: %s\n\n", remove->info.name);
    free(remove);

    return;
}

void printHeap(Heap *heap)
{
    if (heap->first == NULL)
    {
        printf("Empty heap!");

        return;
    }

    Node *node = heap->first;

    for (node = heap->first; node != NULL; node = node->next)
    {
        printf("Name: %s\nAge: %d\n\n",
               node->info.name,
               node->info.age);
    }

    return;
}

void clear(Heap *heap)
{
    while (heap->first != NULL)
    {
        pop(heap);
    }

    free(heap);

    return;
}

int main()
{
    Person p1, p2, p3, p4;
    strcpy(p1.name, "Juliano");
    p1.age = 23;

    strcpy(p2.name, "Augusto");
    p2.age = 20;

    strcpy(p3.name, "Luiz");
    p3.age = 20;

    strcpy(p4.name, "Bruna");
    p4.age = 19;

    Heap *heap = reset();

    push(heap, p1);
    push(heap, p2);
    push(heap, p3);

    printHeap(heap);

    pop(heap);
    pop(heap);

    printHeap(heap);

    push(heap, p4);

    printHeap(heap);

    pop(heap);

    printHeap(heap);

    clear(heap);

    return 0;
}