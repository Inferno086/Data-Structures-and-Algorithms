#include <iostream>
using namespace std;

const int N = 100;

class Stack
{
    private:
        int top;
        int size;
        int *arr;
    public:
        Stack();
        void push(int);
        int pop();
        int peek(int);
        void display();
        bool isEmpty();
        bool isFull();
};

Stack :: Stack()
{
    top = -1;
    size = 0;
    arr = new int[N];
}

void Stack :: push(int x)
{
    if(this -> isFull())
    {
        cout << "The Stack is Full!\n";
    }
    else
    {
        top++;
        *(arr + top) = x;
        size++;
    }
}

int Stack :: pop()
{
    if(this -> isEmpty())
    {
        cout << "The Stack is Empty!\n";
        return 0;
    }
    else
    {
        int temp = *(arr + top);
        top--;
        size--;
        return temp;
    }
}

int Stack :: peek(int index)
{
    if(index >= size || index < 0)
    {
        cout << "Please enter a valid index!\n";
        return 0;
    }
    else
    {
        return *(arr + index);
    }
}

void Stack :: display()
{
    cout << "The Stack is : ";
    for(int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

bool Stack :: isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Stack :: isFull()
{
    if(top == N-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.display();
    s1.pop();
    s1.display();
    cout << s1.peek(2) << endl;
    // cout << s1.peek(-1) << endl;
    // cout << s1.peek(4) << endl;
    // cout << s1.peek(0) << endl;
    // s1.pop();
    // s1.display();
    // s1.pop();
    // s1.display();
    // s1.pop();
    // s1.display();
    // s1.pop();
    // s1.display();
    // s1.pop();
    // s1.display();
    // s1.pop();
    // s1.display();
    // s1.push(1);
    // s1.display();
    return 0;
}