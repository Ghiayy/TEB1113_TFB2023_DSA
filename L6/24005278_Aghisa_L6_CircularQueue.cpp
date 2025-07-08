/*
 ID: 24005278
  Name: Aghisa Zahra
  Group: G2
  Lab: L6 (Circular Queue)
 */

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (front == nullptr) {
            front = rear = new_node;
            rear->next_ptr = front; // circular link
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
            rear->next_ptr = front;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            cout << "Dequeued: " << front->name << endl;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next_ptr;
            rear->next_ptr = front;
            cout << "Dequeued: " << temp->name << endl;
            delete temp;
        }
    }

    void display_queue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue: ";
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != front);
        cout << front->name << " (back to front)" << endl;
    }
};

int main() {
    cout << "Queue" << endl;
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmad");
    queue.enqueue("Alice");
    queue.enqueue("Hamza");

    queue.display_queue();

    queue.dequeue();

    cout << "After dequeueing: " << endl;
    queue.display_queue();

    return 0;
}

