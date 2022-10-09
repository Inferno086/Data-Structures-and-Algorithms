#include <iostream>
using namespace std;

class NODE
{
    public:
        int key;
        NODE* left;
        NODE* right;
        int height;
};

NODE* createNode(int data)
{
    NODE* newnode = new NODE();
    newnode -> key = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> height = 1;
}

int getHeight(NODE* n)
{
    if(n == NULL)
    {
        return 0;
    }
    return n -> height;
}

int getBalanceFactor(NODE* n)
{
    if(n == NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(n -> left) - getHeight(n -> right);
    }
}

int max(int a, int b)
{
    // Returns the greater number between a and b
    return a > b ? a : b;
}

NODE* rightRotate(NODE* y)
{
    NODE* x = y -> left;
    NODE* T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    
    x -> height = max(getHeight(x -> right), getHeight(x -> left)) + 1;
    y -> height = max(getHeight(y -> right), getHeight(y -> left)) + 1;

    return x;
}

NODE* leftRotate(NODE* x)
{
    NODE* y = x -> right;
    NODE* T2 = y -> left;
    y -> left = x;
    x -> right = T2;

    x -> height = max(getHeight(x -> right), getHeight(x -> left)) + 1;
    y -> height = max(getHeight(y -> right), getHeight(y -> left)) + 1;

    return y;
}

NODE *insert(NODE* node, int key){
    if (node == NULL)
    {
        return  createNode(key);
    }
    if (key < node->key)
    {
        node->left  = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
 
    node -> height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left insertion : rightRotate
    if(bf > 1 && key < node -> left -> key)
    {
        return rightRotate(node);
    }

    // Right Right insertion : leftRotate
    if(bf < -1 && key > node -> right -> key)
    {
        return leftRotate(node);
    }

    // Left Right insertion : leftRotate -> rightRotate
    if(bf>1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left insertion : rightRotate -> leftRotate
    if(bf < -1 && key < node -> right -> key)
    {
        node -> right = rightRotate(node -> right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(NODE *root)
{
    if(root != NULL)
    {
        cout << root->key;
        preOrder(root->left);
        preOrder(root->right);
    }
}



int main()
{
    NODE* root = NULL;
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}