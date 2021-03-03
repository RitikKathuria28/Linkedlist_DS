#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertnode(struct node **head, int value)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->next = *head;

    *head = new;
}
void printlist(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("The node is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void remove_duplicate(struct node *head)
{
    struct node *ptr, *ptr1;
    ptr = head;

    while (ptr->next != NULL)
    {
        if (ptr->data == ptr->next->data)
        {
            ptr1 = ptr->next->next;
            free(ptr->next);
            ptr->next = ptr1;
            printf("Duplicate removed\n");
        }

        else
        {
            ptr = ptr->next;
        }
    }
}

void main()
{
    struct node *head = NULL;
    insertnode(&head, 5);
    insertnode(&head, 5);
    insertnode(&head, 4);
    insertnode(&head, 3);
    insertnode(&head, 2);
    insertnode(&head, 2);

    remove_duplicate(head);

    printlist(head);
}