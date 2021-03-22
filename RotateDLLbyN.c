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
void rotateDLL(struct node **head , int value)
{
    struct node *p1,*p2;
    for(int i=0; i<value;i++)
    {
        p1 = *head;
        p2 = *head;
        while(p2->next!=NULL)
        {
            p2 = p2->next;
        }
        p2->next = p1;
        p1->prev = p2;
        *head = p1->next;
        p1->next->prev = NULL;
        p1->next = NULL;


    }
}
void main()
{
    int n;
    struct node *head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
    printf("Enter the value by which you want to rotate the linked list\n");
    scanf("%d",&n);
    printf("Linked List:\n");
    printlist(head);
    rotateDLL(&head,n);
    printf("\nList after rotating %d times\n",n);
    printlist(head);
}