#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void addnode(struct node **head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = (*head);
    (*head) = new;
}

void printlist(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node *add(struct node *head, struct node *head1)
{
    struct node *p, *p1, *p2;
    p = head;
    p1 = head1;
    int carry = 0;
    int sum = 0;
    while (p1 != NULL)
    {
        sum = p->data + p1->data + carry;

        carry = (sum >= 10) ? 1 : 0;

        sum = sum % 10;

        p->data = sum;

        p2 = p;
        p = p->next;
        p1 = p1->next;
    }

    if (carry == 1)
    {
        while (p != NULL)
        {

            sum = p->data + carry;
            carry = (sum >= 10) ? 1 : 0;
            sum = sum%10;
            p->data = sum;
            p2 = p;
            p = p->next;
        }
        if (carry == 1)
        {

            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->data = carry;
            new->next = NULL;
            p2->next = new;
        }
    }
    return head;
}

void main()
{
    struct node *head = NULL;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    addnode(&head, 9);
    addnode(&head, 9);
    addnode(&head, 9);

    addnode(&head1, 9);
    addnode(&head1, 9);
    addnode(&head1, 9);
    

    printlist(head);
    printf("\n");
    printlist(head1);
    head = reverse(head);
    head1 = reverse(head1);
    head = add(head, head1);

    head = reverse(head);
    printf("\n");
    printlist(head);
}
