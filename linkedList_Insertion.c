#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void display(struct node *head)
{
    // This function prints out the Linked List

    printf("The Linked List is : ");
    struct node *temp = head;
    while(temp != 0)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

int numOfElements(struct node *head1)
{
    // Returns the number of elements in the Linked List

    int count = 0;
    struct node *temp;
    temp = head1;
    while(temp != 0)
    {
        temp = temp -> next;
        count++;
    }
    return count;
}

void insertFirst(struct node **head1,struct node **newNode)
{
    // Inserts an element at first position
    // We need to use double pointers here as in C, even pointer arguments are passed by value.

    (*newNode) -> next = *head1;
    *head1 = *newNode;
}

void insertLast(struct node **head1,struct node **newNode)
{
    // Inserts an element at Last position
    // We need to use double pointers here as in C, even pointer arguments are passed by value.
    // We need to traverse through the list till we get the last element

    struct node *temp;
    temp = *head1;
    while(temp -> next != 0)
    {
        temp = temp -> next;
    }
    // Now temp points to the last node

    temp -> next = *newNode;
    (*newNode) -> next = 0;
}

void insertPos(struct node **head1, struct node **newNode, int pos)
{
    // Inserts new node after given position

    struct node *temp;
    temp = *head1;

    for(int i = 1; i < pos; i++)
    {
        temp = temp -> next;
    }

    (*newNode) -> next = temp -> next;
    temp -> next = (*newNode);
}

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

    display(head);

    // Inserting an element at first position

    struct node *newnode1;
    newnode1 = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data for first position : ");
    scanf("%d", &newnode1->data);
    newnode1 -> next = 0;

    // Getting newnode1 into our Linked List

    insertFirst(&head, &newnode1);

    // newnode1 -> next = head;
    // head = newnode1; // These lines also enter the element like insertFirst()

    // Displaying the new L.L.

    display(head);

    // Inserting an element at Last position

    struct node *newnode2;
    newnode2 = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data for Last position : ");
    scanf("%d", &newnode2->data);
    newnode2 -> next = 0;

    // Getting newnode2 at last position

    insertLast(&head, &newnode2);

    // Displaying the new L.L.

    display(head);

    // Getting the number of elements

    int count = numOfElements(head);
    printf("\nThe number of elements is : ");
    printf("%d", count);

    // Inserting an element after a given position node

    int pos;
    printf("Enter the position after which you want to insert new node : ");
    scanf("%d", &pos);

    if(pos > count)
    {
        printf("Invalid Position!");
    }
    else
    {
        struct node *newnode3;
        newnode3 = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data for this position : ");
        scanf("%d", &newnode3->data);
        newnode3 -> next = 0;   

        insertPos(&head, &newnode3, pos);
    }

    // Displaying the Linked List
    display(head);

    return 0;
}