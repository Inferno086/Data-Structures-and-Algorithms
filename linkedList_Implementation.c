#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main()
{
    struct node *head, *newnode, *temp;
    head = 0; // head is a void pointer
    int choice = 1;

    while(1)
    {
        // Creating a new node
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d", &newnode->data);
        newnode -> next = 0;

        // Linking the new node to the previous node
        if(head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }

        // Asking user to continue or exit
        printf("\nDo you want to enter another node(0,1) : ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    }

    // Traversing through the Linked List
    printf("The Linked List is : ");
    temp = head;
    while(temp != 0)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }

    return 0;
}