#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // renamed function but same work
    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    bool search(int key) {
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->data == key) return true;
        }
        return false;
    }

    void deleteNode(int key) {
        if (!head) return;

        if (head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != key) {
            temp = temp->next;
        }

        if (!temp->next) return;

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, key;

    do {
        cout << "\n=== Linked List Menu ===\n";
        cout << "1. Insert at Front\n";
        cout << "2. Search Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Reverse List\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertFront(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> key;
            cout << (list.search(key) ? "Found!" : "Not Found!") << endl;
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteNode(key);
            break;
        case 4:
            list.reverse();
            cout << "List reversed.\n";
            break;
        case 5:
            cout << "Linked List: ";
            list.display();
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);

    return 0;
}