#include<iostream>
using namespace std;

class Stack{
    public: 
        int top;
        int capacity;
        int size;
        int *arr; 

    Stack(int n)
    {
        this->arr = new int[n];
        this->top = -1;
        this->size = 0;
        this->capacity = n;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push()
    {
        if (top == capacity -1 )
        {
            cout << "Can't Push New Element, Stack is Overflow ..." << endl << endl;
            return;
        }
        
        this->top++;

        int elem;

        cout << "Enter the new element: ";
        cin >> elem;

        arr[top] = elem;
        size++;

        cout << "Push Operation successfull ..." << endl << endl;
    }

    void pop()
    {   
        if (top == -1)
        {
            cout << "Can't Remove an Element, Stack is Underflow ..." << endl << endl;
            return;
        }

        top--;
        size--;
        cout << "Pop Operation Successfull ... "<< endl << endl;
    }   

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty ..." << endl << endl;
            return;
        }
        
        cout << " ---- " << endl;
        for(int i=size-1; i>=0; i--)
        {
            cout << "| " << arr[i] << " |" << endl;
        }
        cout << " ---- " << endl << endl;
    }

    void isEmpty()
    {
        if (top == -1)
        {
            cout << "Yes! Stack is Empty ..." << endl << endl;
            return;
        }
        cout << "Nope! Stack is not Empty ..." << endl << endl;
    }

    void isFull()
    {
        if (top == capacity - 1)
        {
            cout << "Yes! Stack is Full ..." << endl << endl;
            return;
        }
        cout << "Nope! Stack is not Full ..." << endl << endl;
    }
};

void info()
{
    cout << "Press 1 for Push" << endl;
    cout << "Press 2 for Pop" << endl;
    cout << "Press 3 for Display the top elements" << endl;
    cout << "Press 4 to check is stack empty or not" << endl;
    cout << "Press 5 to check is stack full or not" << endl;
    cout << "Press 0 to Exit " << endl;
}

int main()
{   
    int n;

    cout << "Please enter the stack size: ";
    cin >> n;

    Stack s1(n);
    int choice;

    do
    {
        info();

        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s1.push();
            break;

        case 2:
            s1.pop();
            break;

        case 4:
            s1.display();
            break;

        case 5:
            s1.isEmpty();
            break;

        case 6:
            s1.isFull();
            break;

        case 0:
            cout << "Exited Successfully ..." << endl;
            break;
        
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 0);
    
}