#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;
};

void display(Node *temp)
{
    cout << "\nThe Linked List is : ";
    while(temp != 0)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

void insertFirst(Node **head, int data)
{
    Node* newnode1 = new Node();
    newnode1 -> data = data;
    newnode1 -> next = *head;
    newnode1 -> prev = 0;
    (*head) = newnode1;
}

void insertLast(Node **tail, Node **newnode1)
{
    (*tail) -> next = *newnode1;
    (*newnode1) -> prev = *tail;
    (*tail) = *newnode1;
}

void insertPos(Node **head, int pos, int data)
{
    Node* newnode1 = new Node();
    newnode1 -> data = data;
    newnode1 -> next = 0;
    newnode1 -> prev = 0;
    Node* temp;
    temp = *head;
    int i = 1;
    while(i < pos - 1)
    {
        temp = temp -> next;
        i++;
    }
    temp -> next -> prev = newnode1;
    newnode1 -> prev = temp;
    newnode1 -> next = temp -> next;
    temp -> next = newnode1;
}

void deleteFirst(Node **head)
{
    Node *temp;
    temp = *head;
    *head = (*head) -> next;
    delete temp;
}

void deleteLast(Node **tail)
{
    Node *temp;
    temp = *tail;
    (*tail) -> prev -> next = 0;
    *tail = (*tail) -> prev;
    delete temp;
}

void deletePos(Node *head, int pos)
{
    Node* temp;
    temp = head;
    int i = 1;
    while(i < pos)
    {
        temp = temp -> next;
        i++;
    }
    temp -> next -> prev = temp -> prev;
    temp -> prev -> next = temp -> next;
    delete temp;
}

void reverse(Node **head, Node **tail)
{
    Node *currentNode, *nextNode;
    currentNode = *head;
    nextNode = 0;

    while(currentNode != 0)
    {
        nextNode = currentNode -> next;
        currentNode -> next = currentNode -> prev;
        currentNode -> prev = nextNode;
        currentNode = nextNode;
    }

    currentNode = *head;
    *head = *tail;
    *tail = currentNode;
}

int main()
{
    int choice = 1;
    Node *head, *tail;
    head = 0;
    
    while(1){
        Node* newnode = new Node();
        cout << "\nEnter data : ";
        cin >> newnode -> data;
        newnode -> next = 0;
        newnode -> prev = 0;

        if(head == 0)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode -> prev = tail;
            tail -> next = newnode;
            tail = tail -> next;
        }

        cout << "Do you want to enter more (0/1)?";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
    }

    display(head);

    // Inserting at first position

    insertFirst(&head, 0);
    cout << "\nAfter insertFirst() : ";
    display(head);

    // Inserting at last position

    Node* newnode1;
    newnode1 = new Node();
    newnode1 -> data = 6;
    newnode1 -> next = 0;
    newnode1 -> prev = 0;
    insertLast(&tail, &newnode1);
    cout << "\nAfter insertLast() : ";
    display(head);

    // Inserting at given position

    insertPos(&head, 3, 9);
    cout << "\nAfter insertPos() : ";
    display(head);

    // Deleting at First position

    deleteFirst(&head);
    cout << "\nAfter deleteFirst() : ";
    display(head);

    // Deleting at Last position

    deleteLast(&tail);
    cout << "\nAfter deleteLast() : ";
    display(head);

    // Deleting at given position

    deletePos(head, 2);
    cout << "\nAfter deletePos() : ";
    display(head);

    // Reversing the Linked List

    reverse(&head, &tail);
    cout << "\nAfter reverse() : ";
    display(head);

    return 0;
}