#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

// ---------- Linked List ----------
void addNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "[LinkedList] Inserted: " << value << endl;
}

void removeNode(int value) {
    if (!head) {
        cout << "[LinkedList] Empty list!" << endl;
        return;
    }

    Node* temp = head;
    if (head->data == value) {
        head = head->next;
        delete temp;
        cout << "[LinkedList] Deleted: " << value << endl;
        return;
    }

    Node* prev = NULL;
    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "[LinkedList] " << value << " not found!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "[LinkedList] Deleted: " << value << endl;
}

void showList() {
    if (!head) {
        cout << "[LinkedList] Empty!" << endl;
        return;
    }
    cout << "List => ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void linkedListMenu() {
    int choice, value;
    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Add Node\n2. Show List\n3. Remove Node\n4. Back\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            addNode(value);
        } else if (choice == 2) {
            showList();
        } else if (choice == 3) {
            cout << "Enter value to remove: ";
            cin >> value;
            removeNode(value);
        }
    } while (choice != 4);
}

// ---------- Sorting ----------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int* L = new int[n1], *R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L; delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // change pivot style
    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pivot && i < high) i++;
        while (arr[j] > pivot && j > low) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortingMenu() {
    int n, choice;
    cout << "\nEnter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    do {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Merge Sort\n2. Quick Sort\n3. Back\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            mergeSort(arr, 0, n - 1);
            cout << "Sorted (Merge): ";
            printArray(arr, n);
        } else if (choice == 2) {
            quickSort(arr, 0, n - 1);
            cout << "Sorted (Quick): ";
            printArray(arr, n);
        }
    } while (choice != 3);
}

// ---------- Binary Search ----------
int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2; // safer mid
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void binarySearchMenu() {
    int n, key;
    cout << "\nEnter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter key: ";
    cin >> key;

    int pos = binarySearch(arr, n, key);
    if (pos != -1)
        cout << "[BinarySearch] Found " << key << " at index " << pos << endl;
    else
        cout << "[BinarySearch] Not Found!" << endl;
}

// ---------- Main ----------
int main() {
    int choice;
    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Linked List\n2. Sorting\n3. Binary Search\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) linkedListMenu();
        else if (choice == 2) sortingMenu();
        else if (choice == 3) binarySearchMenu();
    } while (choice != 4);

    cout << "Program Closed." << endl;
    return 0;
}