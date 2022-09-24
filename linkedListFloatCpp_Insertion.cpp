#include <iostream>
using namespace std;

template<class T>
class Node
{
    public:
        T data;
        Node* next;
};

void display(Node<float> *head)
{
    // This function prints out the Linked List

    cout << "The Linked List is : ";
    Node<float> *temp = head;
    while(temp != 0)
    {
        cout << temp -> data << ", ";
        temp = temp -> next;
    }
}

int numOfElements(Node<float> *head1)
{
    // Returns the number of elements in the Linked List

    int count = 0;
    Node<float> *temp;
    temp = head1;
    while(temp != 0)
    {
        temp = temp -> next;
        count++;
    }
    return count;
}

void insertFirst(Node<float> **head1,Node<float> **newNode)
{
    // Inserts an element at first position
    // We need to use double pointers here as in C, even pointer arguments are passed by value.

    (*newNode) -> next = *head1;
    *head1 = *newNode;
}

void insertLast(Node<float> **head1,Node<float> **newNode)
{
    // Inserts an element at Last position
    // We need to use double pointers here as in C, even pointer arguments are passed by value.
    // We need to traverse through the list till we get the last element

    Node<float> *temp;
    temp = *head1;
    while(temp -> next != 0)
    {
        temp = temp -> next;
    }
    // Now temp points to the last node

    temp -> next = *newNode;
    (*newNode) -> next = 0;
}

void insertPos(Node<float> **head1, Node<float> **newNode, int pos)
{
    // Inserts new node after given position

    Node<float> *temp;
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
    Node<float> *head, *newnode, *temp;
    head = 0; // head is a void pointer
    int choice = 1;

    while(1)
    {
        // Creating a new node

        Node<float>* newnode = new Node<float>();
        cout << "Enter the data : ";
        cin >> newnode->data;
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

        cout << "\nDo you want to enter another node(0,1) : ";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
    }

    // Traversing through the Linked List

    display(head);

    // Inserting an element at first position

    Node<float>* newnode1 = new Node<float>();
    cout << "\nEnter the data for first position : ";
    cin >> newnode1->data;
    newnode1 -> next = 0;

    // Getting newnode1 into our Linked List

    insertFirst(&head, &newnode1);

    // newnode1 -> next = head;
    // head = newnode1; // These lines also enter the element like insertFirst()

    // Displaying the new L.L.

    display(head);

    // Inserting an element at Last position

    Node<float>* newnode2 = new Node<float>();
    cout << "\nEnter the data for Last position : ";
    cin >> newnode2->data;
    newnode2 -> next = 0;

    // Getting newnode2 at last position

    insertLast(&head, &newnode2);

    // Displaying the new L.L.

    display(head);

    // Getting the number of elements

    int count = numOfElements(head);
    cout << "\nThe number of elements is : ";
    cout << count;

    // Inserting an element after a given position node

    int pos;
    cout << "Enter the position after which you want to insert new node : ";
    cin >> pos;

    if(pos > count)
    {
        cout << "Invalid Position!";
    }
    else
    {
        Node<float>* newnode3 = new Node<float>();
        cout << "\nEnter the data for this position : ";
        cin >> newnode3->data;
        newnode3 -> next = 0;   

        insertPos(&head, &newnode3, pos);
    }

    // Displaying the Linked List
    display(head);

    return 0;
}