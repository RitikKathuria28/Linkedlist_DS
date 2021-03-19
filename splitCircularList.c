/* Program to split a circular linked list into two halves */
#include<stdio.h> 
#include<stdlib.h> 


struct Node 
{ 
int data; 
struct Node *next; 
}; 


void splitList(struct Node *head, struct Node **head1_ref, 
											struct Node **head2_ref) 
{
    int size =1;
    struct Node *ptr,*last;
    last = head;
    ptr = head->next;
    while(ptr != head)
    {
        ptr = ptr->next;
        size = size + 1;
        
    }
    

    for(int i=1;i<size;i++)
    {
        last = last->next;
    }
    
    if((size%2) == 0)
    {
        for(int k=0;k<(size/2)-1;k++)
        {
            ptr = ptr->next;
        }
        
    }
    
    if((size%2) != 0)
    {
        for(int k=0;k<(size-1)/2;k++)
        {
            ptr = ptr->next;
        }
        
    }
    
    *head2_ref = ptr->next;
    last->next = *head2_ref;
    *head1_ref = head;
    ptr->next = head;
}


void push(struct Node **head_ref, int data) 
{ 
struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node)); 
struct Node *temp = *head_ref; 
ptr1->data = data; 
ptr1->next = *head_ref; 
	

if(*head_ref != NULL) 
{ 
	while(temp->next != *head_ref) 
	temp = temp->next;		 
	temp->next = ptr1; 
} 
else
	ptr1->next = ptr1; /*For the first node */

*head_ref = ptr1;	 
} 


void printList(struct Node *head) 
{ 
struct Node *temp = head; 
if(head != NULL) 
{ 
	printf("\n"); 
	do { 
	printf("%d ", temp->data); 
	temp = temp->next; 
	} while(temp != head); 
} 
} 

/* Driver program to test above functions */
int main() 
{ 
int list_size, i; 
	
/* Initialize lists as empty */
struct Node *head = NULL; 
struct Node *head1 = NULL; 
struct Node *head2 = NULL; 

/* Created linked list will be 12->56->2->11 */
push(&head, 12); 
push(&head, 56); 
push(&head, 2); 
push(&head, 11); 
push(&head, 15); 

printf("Original Circular Linked List"); 
printList(head);	 

/* Split the list */
splitList(head, &head1, &head2); 

printf("\nFirst Circular Linked List"); 
printList(head1); 

printf("\nSecond Circular Linked List"); 
printList(head2); 
	
getchar(); 
return 0; 
} 
