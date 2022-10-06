#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* createNode(int data)
{
    Node* newnode;
    newnode = new Node();

    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return newnode;
}

void preOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        cout << root -> data;
        preOrderTraversal(root -> left);
        preOrderTraversal(root -> right);
    }
}

void postOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data; 
}

void inOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root -> left);
        cout << root -> data;
        inOrderTraversal(root -> right);
    }
}

int main()
{
    // Creating the tree
    Node *p0 , *p1, *p2, *p3, *p4;
    p0 = createNode(7);
    p1 = createNode(5);
    p2 = createNode(1);
    p3 = createNode(4);
    p4 = createNode(6);

    // Linking the nodes
    p0 -> left = p1;
    p0 -> right = p4;
    p1 -> left = p2;
    p1 -> right = p3;

    // The tree looks like this :-
    //       7
    //     /   \
    //    5     6
    //   / \
    //  1   4

    // Traversals
    preOrderTraversal(p0);
    cout << endl;
    postOrderTraversal(p0);
    cout << endl;
    inOrderTraversal(p0);
    cout << endl;

    return 0;
}