// integer linked list implementation 

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "ll.h"

// allocate a head node
node* create(int val)
{
    node *head;
    if ((head = (node*)malloc(sizeof(node*))) == NULL)
    {
        printf("No avail memory\n");
        exit(0);
    }
    head->data = val;
    head->next = NULL;
    return head;
}

// deallocate the list referenced by head
void kill(node *head)
{
    node *dead;

    while (head != NULL)
    {
        dead = head;
        head = head->next;
        // display(head);
        free(dead);
    }
}

// allocates and inserts node with data->val at end of list
void insert(node *head, int val)
{
    // setup node
    node *new_node = create(val);

    // loop through the list till last node
    node *curr = head;
    node *next = head->next;
    while (next != NULL)
    {
        curr = next;
        next = curr->next;
    }

    // attach node to end of the list
    curr->next = new_node;

}

// removes a node from head's list at the specified index
// index out of range will cause seg fault (obv)
void eliminate(node **head_ptr, int index)
{
    node *dead;
    node *head = *head_ptr;

    if (index == 0)
    {
        // printf("head\n");
        dead = *head_ptr;
        *head_ptr = head->next;
        dead->next = NULL;
        free(dead);
        return;
    }

    int curr_index = 0;

    // loop through the list till one before index
    node *curr = head;
    node *next = head->next;
    while (next != NULL)
    {
        if (curr_index == (index - 1))
        {
            break;
        }
        curr = next;
        next = curr->next;
        curr_index++;
    }

    // CASES
    dead = curr->next;

    if (dead->next == NULL)
    {
        // printf("tail\n");
        curr->next = NULL;
        free(dead);
        return;
    }

    // base
    // printf("base\n");
    curr->next = dead->next;
    dead->next = NULL;
    free(dead);

}

// returns the size of the list
int list_size(node *head)
{
    // if we have a head size must at least be one
    int size = 1;

    // loop through the list till last node
    node *curr = head;
    node *next = head->next;
    while (next != NULL)
    {
        curr = next;
        next = curr->next;
        size++;
    }

    return size;
}

// returns an index if list contains node with val, otherwise -1
int contains(node* head, int val)
{    
    int index = 0;

    // loop through the list till last node
    node *curr = head;
    node *next = head->next;
    while (next != NULL)
    {
        if (curr->data == val)
        {
            return index;
        }
        curr = next;
        next = curr->next;
        index++;
    }

    return -1;
}

// print contents of list
void display(node *head)
{
    node *curr = head;

    while(curr != NULL)
    {
        printf("[%d]->", curr->data);
        curr = curr->next;
    }

    printf("NULL\n");
}