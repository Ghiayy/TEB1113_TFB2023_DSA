/*
 ID: 24005278
  Name: Aghisa Zahra
  Group: G2
  Lab: L4 (Singly Circular)
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

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(string name) {
        Node* new_node = new Node(name);

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            tail->next_ptr = head;
        }
        else
        {
            tail->next_ptr = new_node;
            tail = new_node;
            tail->next_ptr = head;
        }
    }

    
    void display_list() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "(back to head: " << head->name << ")" << endl;
    }

    void delete_by_value(string val) {
        if (head == nullptr) return;

        Node* current = head;
        Node* previous = tail;

        if (head == tail && head->name == val) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        do {
            if (current->name == val) {
                if (current == head) {
                    head = head->next_ptr;
                    tail->next_ptr = head;
                } else if (current == tail) {
                    tail = previous;
                    tail->next_ptr = head;
                } else {
                    previous->next_ptr = current->next_ptr;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next_ptr;
        } while (current != head);
    }

    ~LinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        tail->next_ptr = nullptr; // break circular link

        while (current != nullptr) {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.add_element("Ali");
    list.add_element("Ahmed");
    list.add_element("Alee");
    list.add_element("Hamza");

    cout << "List before deletion: ";
    list.display_list();

    list.delete_by_value("Ahmed");

    cout << "List after deleting 'Ahmed': ";
    list.display_list();

    return 0;
}

