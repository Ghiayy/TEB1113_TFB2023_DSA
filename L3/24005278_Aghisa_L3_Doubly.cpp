/*
 ID: 24005278
  Name: Aghisa Zahra
  Group: G2
  Lab: L3 (Doubly)
 */

#include <iostream>
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

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void display_list() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->name << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void delete_value(string name) {
        Node* curr = head;

        while (curr != nullptr && curr->name != name) {
            curr = curr->next;
        }

        if (curr == nullptr) return; 

        if (curr == head) {
            head = curr->next;
            if (head != nullptr) head->prev = nullptr;
        }
        // Node is tail
        else if (curr == tail) {
            tail = curr->prev;
            if (tail != nullptr) tail->next = nullptr;
        }
        
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    DoublyLinkedList std_list;

    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    cout << "Before deletion: ";
    std_list.display_list();

    std_list.delete_value("Ahmed");

    cout << "After deletion: ";
    std_list.display_list();

    return 0;
}

