/*
 ID: 24005278
 Name: Aghisa Zahra
 Group: G2
 Lab: L4 (Doubly Circular)
 */

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
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

    // Add node at the end
    void add_element(string name) {
        Node* new_node = new Node(name);

        if (head == nullptr) {
            head = tail = new_node;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = head;
            head->prev = new_node;
            tail = new_node;
        }
    }

    void display_list() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head: " << head->name << ")" << endl;
    }

    // Delete node by value
    void delete_by_value(string val) {
        if (head == nullptr) return;

        Node* current = head;

        do {
            if (current->name == val) {
                if (current == head && current == tail) {
                    // Only one node
                    delete current;
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                    delete current;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                    delete current;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                return;
            }
            current = current->next;
        } while (current != head);
    }

    ~LinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);

        head = nullptr;
        tail = nullptr;
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

