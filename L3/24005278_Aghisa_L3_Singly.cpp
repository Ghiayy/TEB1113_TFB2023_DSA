/*
 ID: 24005278
  Name: Aghisa Zahra
  Group: G2
  Lab: L3 (Singly)
 */

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = node;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = node;
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
        if (head == nullptr) return;

        // If head is the node to delete
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->name != name) {
            curr = curr->next;
        }

        if (curr->next != nullptr) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    LinkedList std_list;

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

