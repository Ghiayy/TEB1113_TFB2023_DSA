/*
 ID: 24005278
  Name: Aghisa Zahra
  Group: G2
  Lab: L6 (Queue)
 */

 
#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    string name;
    Node *next_ptr;
   
    Node(string name,  Node *next_ptr = nullptr)
    {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;
    
public:
    Queue()
        {
        front = nullptr;
        rear = nullptr;
        }

void enqueue(string name){
    Node* new_node = new Node(name);
    
    if (front == nullptr){
        front = rear = new_node;
    }
    else{
        rear->next_ptr = new_node;
        rear = new_node;
    }
}

void dequeue(){
    if(front == nullptr){
        cout<<"Queue is empty"<<endl;
        return;
    }
    
    Node* temp = front;
           front = front->next_ptr;
           cout << "Dequeued: " << temp->name << endl;
           delete temp;
    
    if (front == nullptr) {
              rear = nullptr;
    }
}
    
    void display_queue() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    cout<<"Queue"<<endl;
    Queue queue;
    
    queue.enqueue("Ali");
    queue.enqueue("Ahmad");
    queue.enqueue("Alice");
    queue.enqueue("Hamza");
    
    cout<<"Queue: ";
    queue.display_queue();
    
    queue.dequeue();
    
    cout<<"After dequeueing: "<<endl;
    queue.display_queue();
    
    return 0;
}
 


