/*
 ID: 24005278
  Name: Aghisa Zahra
  Group: G2
  Lab: L5 (Stack)
 */

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Stack {
    
public:
    Node* top;
    int max_size;
    int current_size;

    Stack(int size) {
        top = nullptr;
        max_size = size;
        current_size = 0;
    }

    bool isFull()
    {
    return current_size == max_size;
    }
    
    bool isEmpty()
    {
        return top == nullptr;
    }
    
    void display()
    {
        if (isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
    Node* current = top;
    cout << "Stack (top to bottom): ";
        
    while (current != nullptr)
    {
        cout << current->name << " ";
        current = current->next_ptr;
    }
        
    cout << endl;
    }

    // add new node at the top
    void push(string name) {
        if (isFull()) {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }

        Node* new_node = new Node(name);
        new_node->next_ptr = top;
        top = new_node;
        current_size++;
        cout << "Pushed: " << top->name << endl;
    }
    
    void peek() {
        if (isEmpty())
        {
            cout << "Stack is empty. Nothing to peek." << endl;
        }
        else
        {
            cout << "Top of stack: " << top->name << endl;
        }
    }

    void pop() {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        top = top->next_ptr;
        cout << "Popped: " << temp->name << endl;
        delete temp;
        current_size--;
    }
};

int main() {
    cout << "Stack" << endl;
    Stack stack(4);

    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Alee");
;
    stack.peek();

    stack.pop();

    cout << "After popping: ";
    stack.peek();

    return 0;
}
