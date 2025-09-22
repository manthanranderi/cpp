#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        clear();
    }

    void creation();
    void traversal();
    void modification();
    void binarySearch();
    void mergeSort();
    void quickSort();
    void clear();
};

void info();

int main() {
    LinkedList list;
    int choice;

    while (choice != 0) {
        info();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.traversal(); 
                break;

            case 2:
                list.creation(); 
                break;

            case 3:
                list.modification(); 
                break;

            case 4:
                list.binarySearch(); 
                break;

            case 5:
                list.mergeSort(); 
                break;

            case 6:
                list.quickSort(); 
                break;

            case 0:
                cout << "Exited Successfully" << endl; 
                break;

            default: 
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}

void info() {
    cout << "== Linked List Menu == " << endl;
    cout << "1. Show Linked List" << endl;
    cout << "2. Create Linked List" << endl;
    cout << "3. Update Linked List" << endl;
    cout << "4. Binary Search" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "0. Exit" << endl;
}

void LinkedList::creation() {
    clear();
    int size, value;

    cout << "Please Enter The Size: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "Array[" << i <<"]: ";
        cin >> value;

        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    cout << "Linked List Created Successfully" << endl << endl;
}

void LinkedList::traversal() {
    if (head == NULL) {
        cout << "List is empty" << endl << endl;
        return;
    }

    Node* temp = head;
    cout << "Your Linked List: ";
    while (temp != NULL) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}

void LinkedList::modification() 
{
    int pos, newVal;

    cout << "Enter position: ";
    cin >> pos;

    cout << "Enter new value: ";
    cin >> newVal;

    Node* temp = head;
    int i = 0;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        cout << "Position not found" << endl << endl;
    }
    else {
        temp->data = newVal;
        cout << "List is Updated" << endl << endl;
    }
}

void LinkedList::binarySearch() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    int arr[100], positionMap[100], n = 0;
    Node* temp = head;

    while (temp != NULL) {
        arr[n] = temp->data;
        positionMap[n] = n;
        temp = temp->next;
        n++;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swap(positionMap[j], positionMap[j + 1]);
            }
        }
    }

    int key;
    cout << "Enter Key to find: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    bool found = false;
    int actualPos = -1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            found = true;
            actualPos = positionMap[mid];
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found) {
        cout << key << " found at original list position: " << actualPos << endl << endl;
    } else {
        cout << key << " not found" << endl << endl;
    }
}

Node* merge(Node* left, Node* right) {
    if (!left)
    {
        return right;
    } 
        
    if (!right)
    {
        return left;
    } 

    Node* result = NULL;

    if (left->data < right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

Node* getMiddle(Node* head) {
    if (!head) return head;
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSortHelper(Node* head) {
    if (!head || !head->next)
    {
        return head;
    }

    Node* mid = getMiddle(head);
    Node* nextToMid = mid->next;
    mid->next = NULL;

    Node* left = mergeSortHelper(head);
    Node* right = mergeSortHelper(nextToMid);

    return merge(left, right);
}

void LinkedList::mergeSort() {
    head = mergeSortHelper(head);
    cout << "List sorted using Merge Sort" << endl << endl;
}

Node* getTail(Node* head) {
    while (head && head->next)
    {
        head = head->next;
    }
    return head;
}

Node* partition(Node* head, Node* end, Node*& newHead, Node*& newEnd) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* current = head;
    Node* tail = pivot;

    while (current != pivot) {
        if (current->data < pivot->data) {
            if (!newHead) newHead = current;
            prev = current;
            current = current->next;
        } else {
            if (prev) prev->next = current->next;
            Node* temp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if (!newHead) newHead = pivot;
    newEnd = tail;

    return pivot;
}

Node* quickSortHelper(Node* head, Node* end) {
    if (!head || head == end)
    {
        return head;
    }

    Node* newHead = NULL;
    Node* newEnd = NULL;

    Node* pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        newHead = quickSortHelper(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortHelper(pivot->next, newEnd);
    return newHead;
}

void LinkedList::quickSort() {
    head = quickSortHelper(head, getTail(head));
    cout << "List sorted using Quick Sort " << endl << endl;
}

void LinkedList::clear() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}