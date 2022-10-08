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
    Node* newnode = new Node();
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

void inOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root -> left);
        cout << root -> data << " ";
        inOrderTraversal(root -> right);
    }
}

// What does the static keyword do here ???
/*static is just a global variable with visibility limited to one
function. So if you declare it static, there is exactly one variable
shared by all the levels of recursion. Without static, the variable
is local, which means each function invocation has its own copy of
variable's state.*/
// After every function call, prev points to the previous node which
// in previous recursive function.

int isBST(Node* root)
{
    static Node* prev = NULL;
    if(root != NULL)
    {
        if(!isBST(root -> left))
        {
            return 0;
        }
        if(prev != NULL && root -> data <= prev -> data)
        {
            return 0;
        }
        prev = root;
        return isBST(root -> right);
    }
    else
    {
        return 1;
    }
}

Node* search(Node* root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root -> data == val)
    {
        return root;
    }
    else if(root -> data > val)
    {
        return search(root -> left, val);
    }
    else
    {
        return search(root -> right, val);
    }
}

Node* searchIter(Node* root, int val)
{
    while(root != NULL)
    {
        if(root -> data == val)
        {
            return root;
        }
        else if(root -> data > val)
        {
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }
    } 
    return NULL; // This is if the tree provided is already NULL
}

void insert(Node* root, int key)
{
    Node* prev = NULL;
    while(root != NULL)
    {
        prev = root;
        if(root -> data == key)
        {
            return;
        }
        else if(root -> data > key)
        {
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }    
    }
    Node* newnode = createNode(key);
    if(prev -> data > key)
    {
        prev -> left = newnode;
    }
    else
    {
        prev -> right = newnode;
    } 
}

Node *inOrderPredecessor(Node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deleteNode(Node *root, int value){

    Node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main()
{
    Node *p0, *p1, *p2, *p3, *p4;

    // Creating the nodes
    p0 = createNode(7);
    p1 = createNode(4);
    p2 = createNode(2);
    p3 = createNode(5);
    p4 = createNode(11);

    // Linking the nodes
    p0 -> left = p1;
    p0 -> right = p4;
    p1 -> left = p2;
    p1 -> right = p3;

    // Using isBST()
    cout << "Is the tree BST : ";
    if(isBST(p0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    // Using search()
    Node* k = search(p0, 11);
    if(k != NULL)
    {
        cout << k -> data << " is present in tree : search()" << endl;
    }
    else
    {
        cout << "Element is not in tree! : search()" << endl;
    }

    // Using searchIter()
    Node* k1 = searchIter(p0, 11);
    if(k != NULL)
    {
        cout << k1 -> data << " is present in tree : searchIter()" << endl;
    }
    else
    {
        cout << "Element is not in tree! : searchIter()" << endl;
    }

    // Inserting new elements
    inOrderTraversal(p0);
    cout << endl;
    insert(p0, 12);
    // insert(p0, 1);
    // insert(p0, 3);
    // insert(p0, 6);
    inOrderTraversal(p0);
    cout << endl;

    // Deleting an element
    deleteNode(p0, 11);
    inOrderTraversal(p0);
    cout << endl;

    return 0;
}