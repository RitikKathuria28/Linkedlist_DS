#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addnode(struct node **head, int data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = (*head);
    (*head) = new;
}

void printlist(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

void addlast(struct node **head, int data)
{
    struct node *ptr; 
    struct node *new = (struct node*)malloc(sizeof(struct node));; 
    new->data = data;

    ptr = (*head);   
    if(ptr == NULL)  
    {  
        
        new->next = NULL;
        (*head) = new;
    }  
    else  
    {  
           while (ptr->next!=NULL)  
        {  
            ptr = ptr -> next;  
            
        }  
        ptr->next = new;
        new->next = NULL;
        // printf("node inserted\n");
    } 
}
struct node *sortedIntersect(struct node *a, struct node *b, struct node *final)
{
    struct node *ptr;
    ptr = final;
    while (a!=NULL && b!=NULL)
    {
        if(a->data == b->data)
        {
            addlast(&final,a->data);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return final;
    

}

void main()
{
    struct node *head1 =NULL;
    struct node *head2 = NULL;
    struct node *final = NULL;
    // addnode(&head1,6);
    addnode(&head1,50);
    addnode(&head1,40);
    addnode(&head1,20);
    addnode(&head1,10);
    printf("First List:\n");
    printlist(head1);

    // addnode(&head2,8);
    // addnode(&head2,6);
    addnode(&head2,40);
    addnode(&head2,15);
    printf("\nSecond list:\n");
    printlist(head2);
    
    final = sortedIntersect(head1, head2,final);
    printf("\nIntersection of two sorted list:\n");
    printlist(final);

    

    
}
