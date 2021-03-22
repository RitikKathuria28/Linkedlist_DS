#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void push(struct node **head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    ptr = *head;
    new->data = data;
    new->prev = NULL;
    if (ptr != NULL)
    {
        ptr->prev = new;
        new->next = *head;
        *head = new;
    }
    else
    {
        new->next = NULL;
        *head = new;
    }
}
void printlist(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
void sum(struct node *head, int data)
{
    struct node *main, *first, *last;
    main = head;
    
    while (main->next != NULL)
    {
        last = head;
        first = main->next;

        while (last->next != NULL)
        {
            last = last->next;
        }
        while (first != NULL && last->prev != main && first != last && last->next != first)
        {
            if ((first->data + last->data) == (data - (main->data)))
            {
                printf("\n(%d,%d,%d)", main->data, first->data, last->data);
                first = first->next;
                last = last->prev;
            }
            else if ((first->data + last->data) < (data - (main->data)))
            {
                first = first->next;
            }
            else if ((first->data + last->data) > (data - (main->data)))
            {
                last = last->prev;
            }
            else
            {
                printf("\t");
            }
        }
        main = main->next;
    }
}
void main()
{
    struct node *head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
    printlist(head);
    printf("Triplets having sum=15 are:-");
    sum(head, 15);
    // printlist(head);
}