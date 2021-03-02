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

int detectloop(struct node *head)
{
    struct node *ptr1, *ptr2;
    ptr1 = head;
    ptr2 = head;
    while (ptr1 != NULL && ptr2 != NULL && ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if (ptr1 == ptr2)
        {
            return 1;
        }
    }
    return 0;
}

void removeloop(struct node **head)
{
    struct node *ptr1, *ptr2;
    ptr1 = *head;
    ptr2 = *head;
    // ptr1 is slow pointer and ptr2 is fast pointer
    ptr1 = ptr1->next;
    ptr2 = ptr2->next->next;
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    // After this both the pointer are at some node of loop
    // printf("\n%d", ptr1->data); // that node

    // To get Size of the loop
    int k = 1;
    ptr2 = ptr2->next;
    while (ptr1 != ptr2)
    {
        ptr2 = ptr2->next;
        k++;
    }
    printf("\nLoop size:%d", k);

    // Placing 1 pointer at head and 2nd pointer at k(loop size) positions ahead of head
    ptr1 = *head;
    ptr2 = *head;
    for (int i = 0; i < k; i++)
    {
        ptr2 = ptr2->next;
    }

    // now moving both pointers one by one , where they meet is the starting point of loop
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    printf("\nNode from where loop starts:%d\n",ptr1->data);

    // Taking the 2 nd pointer at 2nd last position of loop and set its next value to NULL
    for (int i = 0; i < k - 1; i++)
    {
        ptr2 = ptr2->next;
    }

    // printf("\n%d",ptr1->data);
    // printf("\n%d",ptr2->data);
    ptr2->next = NULL;
    printf("\nLOOP REMOVED\n");
}

void main()
{
    struct node *head;
    insertnode(&head, 2);
    insertnode(&head, 3);
    insertnode(&head, 4);
    insertnode(&head, 5);
    insertnode(&head, 6);
    insertnode(&head, 7);

    head->next->next->next->next->next->next = head->next->next; // creating sample loop
    if (detectloop(head))
    {
        printf("Loop detected");
        removeloop(&head);
    }
    else
    {
        printf("loop not detected");
    }
    
    printf("\nFinal List\n");
    printlist(head);
}