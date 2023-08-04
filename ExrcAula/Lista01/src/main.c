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
} List;

List *reset()
{
    List *list = (List *)malloc(sizeof(List));
    list->first = NULL;
    return list;
}

void push(List *list, Item item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = item;

    // Insere no início
    if ((list->first == NULL) || (list->first->info.id > newNode->info.id))
    {
        newNode->next = list->first;
        list->first = newNode;
        return;
    }
    
    // Insere em ordem crescente
    Node *current = list->first;   
    while (current->next != NULL)
    {
        if (current->next->info.id > newNode->info.id) break;
        
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

Node* pop(List *list)
{
    if (list->first == NULL)
    {
        return NULL;
    }

    Node *removeP = list->first;
    list->first = list->first->next;
    removeP->next = NULL;

    return removeP;
}

Item popId(List *list, int id)
{
    if (list->first == NULL)
    {
        Item empty;
        strcpy(empty.name, "");
        empty.id = 0;
        empty.price = 0.0;
        return empty;
    }

    Node *currentP = list->first;
    Node *removeP = list->first->next;
    while ((removeP != NULL) && (removeP->info.id != id))
    {
        currentP = removeP;
        removeP = removeP->next;
    }
    
    if (removeP != NULL)
    {
        currentP->next = removeP->next;
        Item removedItem = removeP->info;
        
        free(removeP);
        return removedItem;
    }
}

void clear(List *list)
{
    while (list->first != NULL) 
    {
        Node *temp = pop(list);
        printf("Item removido: %s\n", temp->info.name);
        
        free(temp);
    }

    free(list);
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

    List *list = reset();

    push(list, i1);
    push(list, i2);
    push(list, i3);
    push(list, i4);
    push(list, i5);

    printf("Item removido: %s\n", popId(list, 9).name);

    clear(list);
    return 0;
}